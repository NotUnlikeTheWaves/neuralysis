#include "matrix.h"
// #include <stdio.h>
#include <iostream>

using namespace neuralysis;
void print_matrix(const matrix &m) {
    for(unsigned int x = 0; x < m.get_rows(); x++) {
        for(unsigned int y = 0; y < m.get_columns(); y++) {
            std::cout <<m[x][y] << " - ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
        // create a matrix from a file
    matrix a = matrix(2, 3);
    a[0][0] = 2;
    a[0][1] = 3;
    a[0][2] = 4;
    a[1][0] = 1;
    a[1][1] = 0;
    a[1][2] = 8;

    matrix b = matrix(3, 2);
    b[0][0] = 1;
    b[0][1] = 16;
    b[1][0] = 6;
    b[1][1] = 8;
    b[2][0] = 9;
    b[2][1] = 4;
 
    std::cout << "Print a" << std::endl;
    print_matrix(a);
    std::cout << "Print b" << std::endl;
    print_matrix(b);

    std::cout << "Print a transpose" << std::endl;
    matrix c = a.transpose();
    print_matrix(c);
    std::cout << c.get_rows() << std::endl;
    std::cout << c.get_columns() << std::endl;

    matrix d = a * b;
    matrix e = b * a;
    std::cout << "Print a*b" << std::endl;
    print_matrix(d);
    std::cout << "Print b*a" << std::endl;
    print_matrix(e);

    std::cout << "Print copy(a*b)" << std::endl;
    matrix f = matrix(e);
    print_matrix(f);
    matrix pl = b + c;
    print_matrix(pl);
    matrix minus = b - c;


    std::cout << "Test minus:: " << std::endl <<std::endl;
    print_matrix(b);
    print_matrix(c);
    print_matrix(minus);
    std::cout << "End Test minus:: " << std::endl <<std::endl;

    matrix o = matrix(2, 3);
    o = a;
    print_matrix(o);
    return 0;
}
