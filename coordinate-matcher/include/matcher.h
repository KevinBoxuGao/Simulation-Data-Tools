#ifndef MATCHER_H
#define MATCHER_H
#include <string>
#include "NodeFile.h"
#include "TempFile.h"

class matcher 
{
    private:
        double ** node_coordinates; 
        double ** temp_coordinates;
        std::string * node_nodes;
        std::string * temp_temps;
        int nodes_num_of_lines, temps_num_of_lines;
    public:
        matcher(NodeFile &nodes, TempFile &temps);
        void match(std::string output_name);
};

#endif 