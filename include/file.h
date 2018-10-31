#ifndef FILE_H
#define FILE_H
#include <string>
#include <fstream>

class file 
{
    protected:
        std::string name;
        std::ifstream file_object;
        double convert_scientific_notation(std::string number);
    public:
        int num_of_lines();  
        virtual double ** coordinates() = 0;
};

#endif