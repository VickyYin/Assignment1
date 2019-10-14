#include <iostream>
#include "matrix.hpp"
#include "connectivity_matrix.hpp"
#include "column_matrix.hpp"
#include "stochastic_matrix.hpp"
#include "transition_matrix.hpp"
#include <unistd.h>

using namespace std;

int main() {
    const double probability = 0.85;
    connectivity_matrix connectivity_matrix1("..//connectivity.txt");
    stochastic_matrix stochastic_matrix1(connectivity_matrix1);
    teleportion_matrix teleportion_matrix1(connectivity_matrix1.get_number_rows());
    transition_matrix transition_matrix1(stochastic_matrix1, teleportion_matrix1, probability);
    column_matrix column_matrix1(connectivity_matrix1.get_number_rows());
    matrix matrix_prev = transition_matrix1 * column_matrix1;
    matrix matrix_cur = transition_matrix1 * matrix_prev;
    while (matrix_prev != matrix_cur) {
        matrix_prev = matrix_cur;
        matrix_cur = transition_matrix1 * matrix_prev;
    }
    double total = 0;
    for (int x = 0; x < matrix_prev.get_number_rows(); ++x) {
        total += matrix_prev.get_value(x, 0);
    }
    matrix matrix_1_x_1(1);
    matrix_1_x_1.set_value(0, 0, 1 / total);
    matrix_prev *= matrix_1_x_1;
    cout << "\nValues: \n" << matrix_prev;
    return 0;
}