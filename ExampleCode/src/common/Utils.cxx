/****************************************************************************
(c) 2005-2017 Copyright, Real-Time Innovations, Inc.  All rights reserved.                                    
RTI grants Licensee a license to use, modify, compile, and create derivative 
works of the Software.  Licensee has the right to distribute object form 
only for use with RTI products.  The Software is provided 'as is', with no
arranty of any type, including any warranty for fitness for any purpose. RTI
is under no obligation to maintain or support the Software.  RTI shall not
be liable for any incidental or consequential damages arising out of the 
use or inability to use the software.
*****************************************************************************/

#include "Utils.h"

#include <iostream>
#include <fstream>
#ifdef RTI_LINUX
#include <SDL2/SDL.h>
#include <sys/time.h>
#endif


PropertyUtil::PropertyUtil(std::string filename)
{
   std::string s;
   std::ifstream cin(filename);
   while (std::getline(cin, s)) _config[s.substr(0, s.find('='))] = s.substr(s.find('=') + 1);

}

std::string PropertyUtil::getStringProperty(std::string property)
{
   std::string str = "";
   if (_config[property].empty())
      return str;
   else
       return _config[property];
}

int PropertyUtil::getIntProperty(std::string property)
{
   int val = 0;
   if (_config[property].empty())
      return val;
   else
      return std::stoi(_config[property]);
}

long PropertyUtil::getLongProperty(std::string property)
{
   long val = 0;
   if (_config[property].empty())
      return val;
   else {
      std::string st = _config[property];
      return std::stol(st);
   }
}

double PropertyUtil::getDoubleProperty(std::string property)
{
   double val = 0.0;
   if (_config[property].empty())
      return val;
   else
      return std::stod(_config[property]);
}

float PropertyUtil::getFloatProperty(std::string property)
{
   float val = 0.0;
   if (_config[property].empty())
      return val;
   else
      return std::stof(_config[property]);
}

void TimestampUtil::getTimestamp(DDS_Long* sec, DDS_Long* nsec) {


#ifdef WIN32
    static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

    SYSTEMTIME  system_time;
    FILETIME    file_time;
    uint64_t    time;
    GetSystemTime(&system_time);
    SystemTimeToFileTime(&system_time, &file_time);
    time = ((uint64_t)file_time.dwLowDateTime);
    time += ((uint64_t)file_time.dwHighDateTime) << 32;

    *sec  = (long)((time - EPOCH) / 10000000L);
    *nsec = (long)(system_time.wMilliseconds * 1000);

#endif
#ifdef RTI_LINUX
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *sec  = tp.tv_sec;
    *nsec = tp.tv_usec * 1000;
#endif

}

void MessageBoxUtil::PopUp(char* text, MessageBoxUtilMBType type)
{
    switch (type) {
	    case MSGBOX_WARNING: 
	    	    
#ifdef WIN32
                MessageBox(0, text, "WARNING", MB_ICONINFORMATION | MB_OK);
#endif
#ifdef RTI_LINUX
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "WARNING", text, NULL);
#endif
                break;

	    case MSGBOX_INFO: 
	    	    
#ifdef WIN32
                MessageBox(0, text, "INFO", MB_ICONINFORMATION | MB_OK);
#endif
#ifdef RTI_LINUX
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "INFO", text, NULL);
#endif
                break;

            case MSGBOX_ATTENTION: 
	    	    
#ifdef WIN32
                MessageBox(0, text, "ATTENTION", MB_ICONEXCLAMATION | MB_OK);
#endif
#ifdef RTI_LINUX
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "ATTENTION", text, NULL);
#endif
                break;
	    default:
		std::cout << "Invalid message box selectio " << type << std::endl;
    }	


}

