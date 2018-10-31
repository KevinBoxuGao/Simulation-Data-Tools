#include <iostream>
int main() {
    double *coord;
    coord = new double[4];
    coord[0] = 4;
    std::cout << coord[0];
    delete [] coord;
    std::cin.get();
    return 0;
}