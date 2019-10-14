//
// Created by Yaqi Yin on 2019-10-13.
//

#include "transition_matrix.hpp"

transition_matrix::transition_matrix(stochastic_matrix& s_m, teleportion_matrix& t_m, double probability): matrix(s_m.get_number_rows(),s_m.get_number_cols()) {
    for (int x = 0; x < get_number_rows(); ++x) {
        for (int y = 0; y < get_number_cols(); ++y) {
            double slot = (s_m.get_value(x,y)*probability)+((1-probability)*t_m.get_value(x,y));
            set_value(x,y,slot);
        }
    }
}