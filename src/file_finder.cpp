#include <iostream>
#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "file_finder.h"
namespace fs = boost::filesystem;

std::string * file_finder::list_directory(const std::string path)
{
    std::string * files = new std::string[3]; 
    
    for(auto & p: fs::directory_iterator(path)) {
        std::string extension = fs::extension(p);
        std::string result = fs::canonical(p).string();
        std::string result2 = fs::basename(p);
        if (extension == ".txt") {
            files[0] = result;
            files[2] = result2;
            continue;
        }
        else if (extension == ".csv") {
            files[1] = result;
            continue;
        }
        else {
            std::cout << "missing input" << std::endl;
        }
    }

    return files;
}

