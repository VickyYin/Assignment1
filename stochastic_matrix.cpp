//
// Created by Yaqi Yin on 2019-10-13.
//

#include "stochastic_matrix.hpp"

stochastic_matrix::stochastic_matrix(connectivity_matrix c_m) : matrix(c_m.get_number_rows(), c_m.get_number_cols()){
    vector<double> col_total;
    for (int col = 0; col < c_m.get_number_cols(); ++col) {
        double total = 0;
        for (int row = 0; row < c_m.get_number_rows(); ++row) {
            total+=c_m.get_value(row,col);
        }
        col_total.push_back(total);
    }
    for (int r = 0; r < get_number_rows(); ++r) {
        for (int c = 0; c < get_number_cols(); ++c) {
            if(col_total[c]!=0) {
                set_value(r,c,(c_m.get_value(r,c)/col_total[c]));
            } else {
                set_value(r,c,(1.0/c_m.get_number_rows()));
            }
        }
    }
}