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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "dataObject.h"


DataObject::DataObject(std::string filename)
{
    std::ifstream infile(filename);
    std::string line = "";
    //std::getline(infile, line);
    std::string val;

    while (std::getline(infile, line)) {
        //std::cout << line << std::endl;
        std::vector<std::string> row; // Create an empty row
        std::stringstream ss(line);
        while (getline(ss, val, ',')) {
            row.push_back(val); // Add an element (column) to the row
        }
        _vec.push_back(row); // Add the row to the main vector
    }
    if (_vec.size() >= 1)
        _line = 1;
    else
        _line = 0;
}

int DataObject::line()
{
    return _line;
}

int DataObject::lines()
{
    return _vec.size();
}

int DataObject::elements()
{
    return _vec[_line].size();
}

void DataObject::nextLine()
{
    _line++;
    if (_line >= _vec.size())
        _line = 1;
}

void DataObject::get(unsigned int n, std::string &str)
{
    std::cout << "line is " << _line << std::endl;
    if (n < _vec[_line].size())
        str = _vec[_line][n];
    else
        str = "";
}

void DataObject::get(unsigned int n, float &value)
{
    if (n < _vec[_line].size())
        value = std::stof(_vec[_line][n]);
    else
        value = 0.0;
}

void DataObject::get(unsigned int n, int &value)
{
    if (n < _vec[_line].size())
        value = std::stoi(_vec[_line][n]);
    else
        value = 0;
}

