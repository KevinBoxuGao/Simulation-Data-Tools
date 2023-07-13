#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include "file.h"

int file::num_of_lines() {
    int lines = 0;
    std::string nodeline;
    
    file_object.open(name);
    if(file_object.is_open())
    { 
        while(getline(file_object,nodeline))
        {
            ++lines;  
        }
        file_object.close();
    }  
    return lines;
}

double file::convert_scientific_notation(std::string number) {
    int index;
    double num, exponent, converted_num;
    std::replace( number.begin(), number.end(), 'e', 'E');
    index = number.find("E");

    try {
        num = stod(number.substr(0,index));
        exponent = stod(number.substr(index+1,4));
        converted_num = num * pow(10, exponent);
        return converted_num;
    } catch(std::invalid_argument) {
        return 0;
    }
}

