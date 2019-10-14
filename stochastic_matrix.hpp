//
// Created by Yaqi Yin on 2019-10-13.
//

#ifndef ASSIGNMENT1_STOCHASTIC_MATRIX_HPP
#define ASSIGNMENT1_STOCHASTIC_MATRIX_HPP
#include "matrix.hpp"
#include "connectivity_matrix.hpp"

class stochastic_matrix : public matrix {
public:
    stochastic_matrix(connectivity_matrix c_m);
};
#endif //ASSIGNMENT1_STOCHASTIC_MATRIX_HPP
