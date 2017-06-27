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

#include <vector>
#include <string>



class DataObject {

private:
   std::vector< std::vector<std::string> > _vec;
   unsigned int _line = 0;

public:
   DataObject(std::string filename);
    
   int line();
   int lines();
   int elements();
   void nextLine();
   void get(unsigned int n, std::string &str);
   void get(unsigned int n, float &value);
   void get(unsigned int n, int &value);

};
