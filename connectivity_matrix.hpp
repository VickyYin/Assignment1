//
// Created by Yaqi Yin on 2019-10-13.
//

#ifndef ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP
#define ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP
#include "matrix.hpp"
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class connectivity_matrix : public matrix {
public:
    connectivity_matrix(double array[],int size);
    connectivity_matrix(string FILE_PATH);
};
#endif //ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP
