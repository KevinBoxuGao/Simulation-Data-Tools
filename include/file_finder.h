#ifndef FILE_FINDER_H
#define FILE_FINDER_H
#include <string> 


class file_finder
{
    public:
        std::string * list_directory(const std::string path);
};

#endif