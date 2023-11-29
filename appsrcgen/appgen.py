# ******************************************************************************
#  (c) 2022,2023 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
#   Licensed according to the terms in the LICENSE.md file located at the root 
#   of this software repository: LICENSE.md
# *****************************************************************************
import sys, os
import json
from pathlib import Path
import xml.etree.ElementTree as ET

class AppSourceGen():
    def __init__(self):
        super().__init__()
        self.configFile = {}
        self.CMakeTop = []
        self.pathConfigFileName = "pathcfg.json"
        self.destPath = ''
        self.projectBaseDir = os.path.abspath('..')
        self.readConfigFile()
        self.readTopCMakeTemplateFile()

    def setDestPath(self, destPath):
        self.destPath = destPath

    # read the top-level CMake file template
    def readTopCMakeTemplateFile(self):
        with open(self.configFile['cmake-top']) as fr:
            self.CMakeTop = fr.readlines()
        fr.close()

    # a recursive text-replacement for updating config paths
    def fixPathBase(self, d, pathBase):
        for k, v, in d.items():
            if isinstance(v, dict):
                self.fixPathBase(v, pathBase)
            else:
                if '${PATH_BASE}' in v:
                    d[k] = v.replace('${PATH_BASE}', pathBase)

    # open/read a config file that points at paths for Connext, type headers, and codegen templates.
    def readConfigFile(self):
        with open(self.pathConfigFileName) as fr:
            self.configFile = json.load(fr)
            self.fixPathBase(self.configFile, self.projectBaseDir)                        
        fr.close()

    # replace tags with type/topic-specific info
    def singleTopicTagReplacements(self, rline, topic, appname):
        rline = rline.replace('{{Loop:Line:Topic:True:HeaderFileNameBase}}', topic['typefile'])
        rline = rline.replace('{{Repl:DataTypeName}}', topic['typename'])
        rline = rline.replace('{{Repl:DataTypePathAndName}}', '{}{}'.format(topic['typepath'], topic['typename']))
        rline = rline.replace('{{Loop:Line:Topic:True:DataTypePathAndName}}','{}{}'.format(topic['typepath'], topic['typename']))
        rline = rline.replace('{{Repl:DataTypePathAndNameUnderscored}}', '{}{}'.format(topic['typepath'], topic['typename']).replace('::', '_'))
        rline = rline.replace('{{Repl:DataTopicName}}', topic['topicname'])
        rline = rline.replace('{{Repl:AppName}}', appname)
        return rline

    # replace tags with app-specific info (not topic/type)
    def noTopicTagReplacements(self, rline, appname):
        rline = rline.replace('{{Repl:AppName}}', appname)
        return rline

    # check if 'tag' component is needed for this topic
    def tagIsInTopic(self, tag, topic):
        if tag == 'True':
            return True
        elif tag == 'Pub':
            return topic['pubsub'] == 'pub'
        elif tag == 'Sub':
            return topic['pubsub'] == 'sub'
        else:
           return tag == topic['code']
           

    # create a CMakeLists.txt file for the example application, in its directory
    # the template file is a verbatim copy of the one used by RTI codegen
    def exportCMakeListsFile(self, appInfo, apDir):
        # read from a template file, then modify the contents and write a new file
        templateFileName = self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['cmake-templ']
        with open(templateFileName) as fr:
            frbuf = fr.readlines()
        fr.close()
        # strip newlines
        frbuf = [line.rstrip() for line in frbuf]

        # step through the lines and make replacements
        for idx, rline in enumerate(frbuf):
            if '{{' in rline:
                rline = rline.replace("{{Repl:AppName}}", appInfo['appname'])
                rline = rline.replace("{{Repl:TypeHeaderIncludePath}}", self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['header-path'])
                rline = rline.replace("{{Repl:TypeLibDebugPath}}", self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['lib-path-debug'])
                rline = rline.replace("{{Repl:TypeLibReleasePath}}", self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['lib-path-release'])
                rline = rline.replace("{{Repl:TypeLibDebugName}}", self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['lib-name-debug'])
                rline = rline.replace("{{Repl:TypeLibReleaseName}}", self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['lib-name-release'])
                rline = rline.replace("{{Repl:TypeFilesBaseDir}}", self.projectBaseDir)
                frbuf[idx] = rline

        # write the CMakeLists.txt file
        cwFileName = Path(apDir, 'CMakeLists.txt')
        with open(cwFileName, mode='wt', encoding='utf-8') as cmfile:
            cmfile.write('\n'.join(frbuf))


        return

    # export the source code file(s) for the example application
    def exportConnextAppSource(self, appInfo):
        # load the selected template for code generation
        useNamespaces = True    # FIXME: this needs to be a config option

        # load the selected template file for this application
        templateFileNames = self.configFile['type-paths'][appInfo['connext']][appInfo['language']]['src-templ']
        for templateFileName in templateFileNames:
            with open(templateFileName, 'r') as tempLfile:
                refLines = tempLfile.readlines()
                tempLfile.close()
                indent = 0
                indentStep = 4

                # strip newlines
                refLines = [line.rstrip() for line in refLines]
                exportLines = []
                # now update the contents line-by-line to match this app
                idx = 0
                while idx < len(refLines):
                    xline = refLines[idx]
                    # is there a TAG in this line?
                    if xline.find('{{') >= 0:
                        tagString = xline[xline.find('{{')+2:xline.find('}}')]
                        tagList = tagString.split(':')
                        if tagList[0] == 'Loop':
                            if tagList[1] == 'Line':            
                                # Work on this line only
                                if tagList[2] == 'Topic': 
                                    # iterate over the topics
                                    for topic in appInfo['topics']:
                                        if tagList[3] == 'True':
                                            addLine = self.singleTopicTagReplacements(xline, topic, appInfo['appname'])
                                            exportLines.append(addLine)
                                            
                            elif tagList[1] == 'Start':
                                # Work on a block of code.  Find the end of the block
                                tagEndString = tagString.replace(':Start:', ':End:')
                                endIdx = [idx for idx, i in enumerate(refLines[idx:]) if tagEndString in i][0] + idx
                                startIdx = idx + 1
                                if tagList[2] == 'Topic':
                                    # iterate over the topics
                                    for topic in appInfo['topics']:
                                        if self.tagIsInTopic(tagList[3], topic):
                                            # copy this block to the export, modifying for tags as you go
                                            for bline in refLines[startIdx:endIdx]:
                                                if '{{' in bline:
                                                    addLine = self.singleTopicTagReplacements(bline, topic, appInfo['appname'])
                                                else:
                                                    addLine = bline
                                                exportLines.append(addLine)
                                            if tagList[4] == '1':
                                                break

                                    # update idx to beyond this block
                                    idx = endIdx
    
                        elif tagList[0] == 'Repl':
                            if tagList[1] == 'DataTypePathAndName' or tagList[1] == 'DataTypePathAndNameUnderscored' or tagList[1] == 'DataTypeName':
                                for topic in appInfo['topics']:
                                    addLine = self.singleTopicTagReplacements(xline, topic, appInfo['appname'])
                                    exportLines.append(addLine)
                            elif tagList[1] == 'AppName':
                                addLine = self.noTopicTagReplacements(xline, appInfo['appname'])
                                exportLines.append(addLine)
                            elif tagList[1] == 'TopicCount':
                                addLine = xline.replace('{{Repl:TopicCount}}', str(len(appInfo['topics'])))
                                exportLines.append(addLine)
                            elif tagList[1] == 'TypeCount':
                                typeSet = set()
                                for topic in appInfo['topics']:
                                    typeSet.add(topic['typepath'] + topic['typename'])
                                addLine = xline.replace('{{Repl:TypeCount}}', str(len(typeSet)))
                                exportLines.append(addLine)
                            elif tagList[1] == 'WriterCount':
                                writerCount = 0
                                for topic in appInfo['topics']:
                                    if topic['pubsub'] == 'pub':
                                        writerCount += 1
                                if writerCount == 0:
                                    writerCount = 1
                                addLine = xline.replace('{{Repl:WriterCount}}', str(writerCount))
                                exportLines.append(addLine)
                            elif tagList[1] == 'ReaderCount':
                                readerCount = 0
                                for topic in appInfo['topics']:
                                    if topic['pubsub'] == 'sub':
                                        readerCount += 1
                                if readerCount == 0:
                                    readerCount = 1
                                addLine = xline.replace('{{Repl:ReaderCount}}', str(readerCount))
                                exportLines.append(addLine)
                            else:
                                print('unknown tag: {} in {}'.format(tagList[1], xline))
    
                    else:
                        exportLines.append(xline)
                    idx += 1
    
                # create source dir (if not exist) and source file, named as appname/appname_main.ext
                dirNameToCreate = os.path.abspath(self.destPath)
                apDir = Path(dirNameToCreate)
                Path(apDir, 'src').mkdir(parents=True, exist_ok=True)
                apDir = Path(apDir, 'src/{}'.format(appInfo['appname']))
                Path(apDir).mkdir(parents=True, exist_ok=True)
                # srcFileToWrite = Path(apDir, '{}_main{}'.format(appInfo['appname'], Path(templateFileName).suffix))
                srcFileNameToWrite = appInfo['appname'] + templateFileName[templateFileName.find('template_')+8:]
                srcFileToWrite = Path(apDir, srcFileNameToWrite)
                f = open(srcFileToWrite, "w")
                for line in exportLines:
                    try:
                        f.write(line + '\n')
                    except Exception:
                        pass
                f.close()
    
                # create CMakeLists.txt file for this app
                self.exportCMakeListsFile(appInfo, apDir)

    def sortHelperLevel(self, filerec):
        return filerec['inclevel']

    # update the include level in the tree (if needed)
    def update_tree_inclevel(self, tree, idx, inclevel):
        if tree[idx]['inclevel'] > inclevel:
            inclevel = tree[idx]['inclevel']
        elif inclevel > tree[idx]['inclevel']:
            tree[idx]['inclevel'] = inclevel
        for incIdx in tree[idx]['includes']:
            self.update_tree_inclevel(tree, incIdx, inclevel+1)


    # collect XML type information from a list of files, merge & export the types as single file.
    def exportXmlDataTypeFile(self, xmlTypeFileList, destPath):
        # we have a starter list of files; put into table and build an include hierarchy
        #  table has: filename, inclevel, filesincluded
        allXmlTypeFilesNeeded = []
        typeFilesToReadList = []
        for xmlFileBase in xmlTypeFileList:
            tmpFileRec = {}
            tmpFileRec['inclevel'] = 0
            tmpFileRec['filename'] = '../datatypes/' + xmlFileBase + '.xml'
            tmpFileRec['includes'] = []
            typeFilesToReadList.append(tmpFileRec['filename'])
            allXmlTypeFilesNeeded.append(tmpFileRec)

        # loop on filenames/include filenames until no more to find
        inclevel = 1
        while len(typeFilesToReadList) > 0:
            buildListOfIncludeFiles = []
            
            # open / read each file in tmp list
            for tmpXmlFile in typeFilesToReadList:
                # get parent file idx in allfiles list
                parentIdx = -1
                for idx, fileItem in enumerate(allXmlTypeFilesNeeded):
                    if fileItem['filename'] == tmpXmlFile:
                        parentIdx = idx
                        break

                if os.path.exists(tmpXmlFile):
                    xmlFileData = ET.parse(tmpXmlFile).getroot()
                    # get any #include statements
                    topIdx = 0
                    for incfile in xmlFileData.iter('include'):
                        incFileName = '../datatypes/' + incfile.attrib['file']

                        # does this incfile already exist in allfiles?
                        fileIdxInList = -1
                        for idx, fileItem in enumerate(allXmlTypeFilesNeeded):
                            if fileItem['filename'] == incFileName:
                                fileIdxInList = idx
                        # if not -- add to allfiles at current inclevel
                        if fileIdxInList == -1:
                            tmpFileRec = {}
                            tmpFileRec['inclevel'] = inclevel
                            tmpFileRec['filename'] = incFileName
                            tmpFileRec['includes'] = []
                            buildListOfIncludeFiles.append(tmpFileRec['filename'])
                            allXmlTypeFilesNeeded.append(tmpFileRec)
                            fileIdxInList = len(allXmlTypeFilesNeeded)-1

                        # add this incfile's index to the 'includes' of the current file in allfiles
                        allXmlTypeFilesNeeded[parentIdx]['includes'].append(fileIdxInList)

                #else:
                #    print('FileNotExist: {}'.format(tmpXmlFile))

            # Overwrite tmpFileToReadList with new list (will loop again or break loop)
            typeFilesToReadList = buildListOfIncludeFiles
            inclevel += 1

        # recursively update the include levels if needed
        for idx, tmpFile in enumerate(allXmlTypeFilesNeeded):
            if tmpFile['inclevel'] == 0:
                self.update_tree_inclevel(allXmlTypeFilesNeeded, idx, 0)


        # now sort allXmlTypeFilesNeeded by highest inclevel first
        allXmlTypeFilesNeeded.sort(reverse=True, key=self.sortHelperLevel)

        # now re-read all of the sorted XML type files into the 'types' insertion point of an empty template file
        xmlTypeTree = ET.parse('./templates/xml_datatypes.xml')
        insertion_point = xmlTypeTree.findall("./types")[0]
        MissingFilePrint = 0
        for xmlFileName in allXmlTypeFilesNeeded:
            if os.path.exists(xmlFileName['filename']):
                xmlFileData = ET.parse(xmlFileName['filename']).getroot()
                for types in xmlFileData.iter('types'):
                    insertion_point.extend(types)
            else:
                if MissingFilePrint == 0:
                    MissingFilePrint = 1
                    print('The following data type files were not found:')
                print('    {}'.format(xmlFileName['filename']))
        if MissingFilePrint == 1:
            print('  These data types will be missing from the {}/systemDataTypes.xml helper file'.format(destPath))
            print('  To include the above types in the helper file:')
            print('    - enable the appropriate data type group by editing ../datatypes/res/types/CMakeLists.txt')
            print('    - rebuild the datatypes')
            print('    - re-run this generator')

        if xmlTypeTree is not None:
            # filter-out any <include> tags
            root = xmlTypeTree.getroot()
            for child in root.iter('types'):
                for incfile in child.findall('include'):
                    child.remove(incfile)
                
            xmlTypeTree.write("{}/systemDataTypes.xml".format(destPath))



# ---------------------------------------------------------
# main: expecting args: 
#       [1] = JSON file with description of apps & topics,
#             and location of type support files.
#       [2] = Destination path (where to write the project)
#             (this is optional, overrides value in JSON file)
#       Also: NDDSHOME / RTIMEHOME env vars
if __name__ == "__main__":
    # default destination path is current dir
    destPath = '.'
    hasCmdLineDestPath = False

    # check arguments
    if len(sys.argv) == 1:
        print('usage: {} cfgFileName <destPath>, where:'.format(sys.argv[0]))
        print('       cfgFileName = JSON-format system configuration file')
        print('       <destPath>  = path to write the generated files')
        exit()
    elif len(sys.argv) == 3:
        destPath = sys.argv[2]
        hasCmdLineDestPath = True

    # initialize and load the configuration
    app = AppSourceGen()
    app.setDestPath(destPath)

    # open and read the JSON file with the system description
    with open(sys.argv[1], 'r') as buildFile:
        # read, load, and close the file
        # FIXME: this needs error handling
        buildFileContents = buildFile.read()
        buildFile.close()
        buildTree = json.loads(buildFileContents)

        # This is for the CMake top-level file
        CMakeAddLine = app.CMakeTop.pop()

        # This is for the launching script
        appNameList = []

        # this is for the list of XML type files (to create one common file)
        xmlTypeFileList = []
        hasProApp= False

        # step through the items:
        for item in buildTree:
            if item == 'dest-path' and hasCmdLineDestPath == False:
                destPath = buildTree[item]
                app.setDestPath(destPath)

            if item == 'app-list':
                # list of applications to generate
                for thisApp in buildTree[item]:
                    app.exportConnextAppSource(thisApp)
                    addLine = CMakeAddLine.replace('{{Repl:AppName}}', thisApp['appname']) + '\n'
                    app.CMakeTop.append(addLine)
                    appNameList.append(thisApp['appname'])

                    # add to the list of XML type files
                    for topicItem in thisApp['topics']:
                        if topicItem['typefile'] not in xmlTypeFileList:
                            xmlTypeFileList.append(topicItem['typefile'])

                    # check if USER_QOS_PROFILES.xml file needs to be copied
                    if thisApp['connext'] == 'pro':
                        hasProApp = True
                            

        # Create a merge-all-types-in-system XML data types file
        app.exportXmlDataTypeFile(xmlTypeFileList, app.destPath)

        # when finished, write the top-level CMakeLists.txt file
        CMakeTopFileName = '{}/CMakeLists.txt'.format(app.destPath)
        with open(CMakeTopFileName, mode='wt', encoding='utf-8') as cmfile:
            cmfile.write(''.join(app.CMakeTop))

        # and create a convenience script to launch all (run-demo.sh)
        launchScriptLines = []
        with open(app.configFile['launch-script']) as fr:
            launchScriptLines = fr.readlines()

        for idx, lline in enumerate(launchScriptLines):
            if '{{Loop:Start:Appname:True:all}}' in lline:
                launchScriptLines.pop(idx)
                newLine = launchScriptLines.pop(idx)
                addCount = 0
                for appname in appNameList:
                    addLine = newLine.replace('{{Repl:AppName}}', appname)
                    launchScriptLines.insert(idx, addLine)
                    addCount += 1
                launchScriptLines.pop(idx+addCount)
            if '{{Loop:End:Appname:True:all}}' in lline:
                launchScriptLines.pop(idx)

        LaunchScriptFileName = '{}/run-demo.sh'.format(app.destPath)
        with open(LaunchScriptFileName, mode='wt', encoding='utf-8') as lfile:
            lfile.write(''.join(launchScriptLines))

        # copy USER_QOS_PROFILES.xml if pro app
        if hasProApp:
            with open('templates/pro_USER_QOS_PROFILES.xml', mode='rt', encoding='utf-8') as qfile:
                qos = qfile.read()
                qfile.close()

            with open('{}/USER_QOS_PROFILES.xml'.format(app.destPath), mode='wt', encoding='utf-8') as qfile:
                qfile.write(qos)
                qfile.close()
