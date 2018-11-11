#include <iostream>
#include <fstream>
#include <string>
#include "TempFile.h"

TempFile::TempFile(std::string file_name) {
    name = file_name;
}

int * TempFile::indexes(std::string line) {
    int * indexes = new int[3];
    unsigned int x, coord_count;
    for(x = 0, coord_count = 0; x < line.length(); x++) {
        if (line[x] == ',')
        {
            indexes[coord_count] = x;
            coord_count++;
        } 
    }
    return indexes;
}

double ** TempFile::coordinates() {
    double ** coord = new double * [3];
    for (int i = 0; i < 4; i++)
    {
        coord[i] = new double[num_of_lines()-9];
    }
    std::string nodeline;
    file_object.open(name);
    if(file_object.is_open())
    { 
        for(int x = 0; x < 9; x++)
        {
            getline(file_object, nodeline);    
        }
        for(int line_number = 0; getline(file_object, nodeline); line_number++) 
        {
            coord[0][line_number] = convert_scientific_notation(nodeline.substr(0, indexes(nodeline)[0]));
            coord[1][line_number] = convert_scientific_notation(nodeline.substr(indexes(nodeline)[0] + 2, indexes(nodeline)[1] - indexes(nodeline)[0] - 2));
            coord[2][line_number] = convert_scientific_notation(nodeline.substr(indexes(nodeline)[1] + 2, indexes(nodeline)[2] - indexes(nodeline)[1] - 2));
        }
        file_object.close();
    }  
    else
    {
        std::cout << "error, file was unable to be opened";
    }
    return coord;
}

std::string * TempFile::temps() {
    std::string * temp = new std::string [num_of_lines()-9];
    std::string nodeline;
    file_object.open(name);
    if(file_object.is_open())
    { 
        for(int x = 0; x < 9; x++)
        {
            getline(file_object, nodeline);    
        }
        for(int line_number = 0; getline(file_object, nodeline); line_number++) 
        {
            temp[line_number] = nodeline.substr(indexes(nodeline)[2] + 2, nodeline.length() - indexes(nodeline)[2] - 2);
        }
        file_object.close();
    }  
    else
    {
        std::cout << "error, file was unable to be opened";
    }
    return temp;
}
