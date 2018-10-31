#include <iostream>
#include <string>
#include "file_finder.h"
#include "file.h"
#include "NodeFile.h"
#include "TempFile.h"
#include "matcher.h"

int main() {       
    file_finder input;

    NodeFile node(input.list_directory("../input")[0]);
    TempFile temp(input.list_directory("../input")[1]);
   
    matcher pair(node, temp);

    pair.match(input.list_directory("../input")[2]);
    
    return 0;
}
