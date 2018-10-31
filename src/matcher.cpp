#include <iostream>
#include <fstream>
#include "matcher.h"

matcher::matcher(NodeFile &nodes, TempFile &temps) {
    node_coordinates = nodes.coordinates();
    node_nodes = nodes.nodes();
    temp_coordinates = temps.coordinates();
    temp_temps = temps.temps();
    nodes_num_of_lines = nodes.num_of_lines();
    temps_num_of_lines = temps.num_of_lines();
}

void matcher::match(std::string output_name) {
    std::ofstream output("../outputs/"+output_name+".txt");
    for(int x = 0; x < (nodes_num_of_lines-2); x++) {
        for(int i = 0; i < (temps_num_of_lines-9); i++) {
            if (temp_coordinates[0][i] - 0.001 < node_coordinates[0][x] && node_coordinates[0][x] < temp_coordinates[0][i] + 0.001) {
                if (temp_coordinates[1][i] - 0.001 < node_coordinates[1][x] && node_coordinates[1][x] < temp_coordinates[1][i] + 0.001) {
                    if (temp_coordinates[2][i] - 0.001 < node_coordinates[2][x] && node_coordinates[2][x] < temp_coordinates[2][i] + 0.001) {
                        output << "BF," + node_nodes[x] + ",TEMP," + temp_temps[i] << std::endl;
                        continue;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    continue;
                }
            }
            else if (i == temps_num_of_lines-8) {
                break;
                std::cout << "error, no match" << std::endl;
            }
            else {
                continue;
            }
        }
    }
    std::cout << "complete" << std::endl;
    output.close();
}

    

