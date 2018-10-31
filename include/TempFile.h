#ifndef TEMPFILE_H
#define TEMPFILE_H
#include <string>
#include <fstream>
#include "file.h"

class TempFile: public file
{
    private:
        int * indexes(std::string line);
    public:
        TempFile(std::string file_name);
        double ** coordinates();
        std::string * temps();
};

#endif