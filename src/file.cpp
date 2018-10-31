#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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

    index = number.find("+");
    num = stod(number.substr(0,index-1));
    exponent = stod(number.substr(index+1,number.length()-(index+1)));
    
    converted_num = num * pow(10, exponent);
    
    return converted_num;
}

