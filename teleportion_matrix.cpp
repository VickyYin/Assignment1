//
// Created by Yaqi Yin on 2019-10-13.
//

#include "teleportion_matrix.hpp"

teleportion_matrix::teleportion_matrix(int n) : matrix(n) {
    for (int r = 0; r < get_number_rows(); ++r) {
        for (int c = 0; c < get_number_cols(); ++c) {
            set_value(r,c,1.0/get_number_rows());
        }
    }
}