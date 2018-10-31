#ifndef NODEFILE_H
#define NODEFILE_H
#include <string>
#include <fstream>
#include "file.h"

class NodeFile: public file
{
    public:
        NodeFile(std::string file_name);
        double ** coordinates();
        std::string * nodes();
};

#endif