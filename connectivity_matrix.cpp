//
// Created by Yaqi Yin on 2019-10-13.
//

#include "connectivity_matrix.hpp"
connectivity_matrix::connectivity_matrix(double *array, int size): matrix(array,size) {
    for (int x = 0; x < sizeof(array); ++x) {
        if(array[x]==0 || array[x]==1) {

        } else {
            throw invalid_argument("Connectivity matrix has values other than 0 or 1");
        }
    }
}

connectivity_matrix::connectivity_matrix(string FILE_PATH) {
    ifstream my_file(FILE_PATH);
    vector<double> array;
    double value;
    while(my_file >> value)
    {
        array.push_back(value);
    }
    connectivity_matrix connectivity_matrix1(array.data(), array.size());
    *this=connectivity_matrix1;
}