#include <iostream>
#include <fstream>
#include <string>
#include "NodeFile.h"

NodeFile::NodeFile(std::string file_name) {
    name = file_name;
}

double ** NodeFile::coordinates() {
    double ** coord = new double * [3];
    for (int i = 0; i < 4; i++)
    {
        coord[i] = new double[num_of_lines()-2];
    }

    std::string nodeline;
    file_object.open(name);
    if(file_object.is_open())
    { 
        for(int x = 0; x < 2; x++)
        {
            getline(file_object, nodeline);    
        }
        for(int line_number = 0; getline(file_object, nodeline); line_number++) 
        {
            coord[0][line_number] = convert_scientific_notation(nodeline.substr(27,21));
            coord[1][line_number] = convert_scientific_notation(nodeline.substr(48,21));
            coord[2][line_number] = convert_scientific_notation(nodeline.substr(69,21));
        }
        file_object.close();
    }  
    else
    {
        std::cout << "error, file was unable to be opened";
    }
    return coord;
}

std::string * NodeFile::nodes() {
    std::string * node = new std::string [num_of_lines()-2];
    std::string nodeline;
    file_object.open(name);
    if(file_object.is_open())
    { 
        for(int x = 0; x < 2; x++)
        {
            getline(file_object, nodeline);    
        }
        for(int line_number = 0; getline(file_object, nodeline); line_number++) 
        {
            node[line_number] = nodeline.substr(2,7);
        }
        file_object.close();
    }  
    else
    {
        std::cout << "error, file was unable to be opened";
    }
    return node;
}