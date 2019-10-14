//
// Created by Yaqi Yin on 2019-10-13.
//

#include "column_matrix.hpp"
column_matrix::column_matrix(int n) :matrix(n,1){
    for (int x = 0; x < n; ++x) {
        set_value(x,0,1.0);
    }
}