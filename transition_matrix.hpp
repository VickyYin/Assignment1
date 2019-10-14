//
// Created by Yaqi Yin on 2019-10-13.
//

#ifndef ASSIGNMENT1_TRANSITION_MATRIX_HPP
#define ASSIGNMENT1_TRANSITION_MATRIX_HPP

#include "matrix.hpp"
#include "stochastic_matrix.hpp"
#include "teleportion_matrix.hpp"

class transition_matrix : public matrix {
public:
    transition_matrix(stochastic_matrix& s_m, teleportion_matrix& t_m, double probability);
};
#endif //ASSIGNMENT1_TRANSITION_MATRIX_HPP
