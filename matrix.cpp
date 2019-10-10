//
// Created by Yaqi Yin on 2019-10-04.
//
#include "matrix.hpp"
using namespace std;
const double matrix::tolerance = 0.00001;
matrix::matrix():number_rows(1),number_columns(1){
      holder = generate_matrix(number_rows,number_columns);
      clear();
}
matrix::matrix(const matrix &copy){
      number_rows = copy.number_rows;
      number_columns = copy.number_columns;
      holder = generate_matrix(number_rows,number_columns);
      for(int x = 0; x < number_rows; ++x){
          for(int y = 0; y < number_columns; ++y){
              holder[x][y] = copy.holder[x][y];
          }
      }
}
matrix::matrix(int n):number_rows(n),number_columns(n){
      if (n <= 0) {
          throw invalid_argument("n should be a positive value");
      }
      holder = generate_matrix(number_rows,number_columns);
      clear;
}
matrix::matrix(int r, int c):number_rows(r),number_columns(c){
    if(r <=0 || c <= 0){
        throw invalid_argument("r and c should be positive values");
    }
    holder = generate_matrix(number_rows, number_columns);
    clear();
}
matrix::matrix(double intArray[], int size ){
    int root = sqrt(size);
    if(root*root == size){
        number_rows = root;
        number_columns = root;
        holder = generate_matrix(number_rows, number_columns);
        int int_array_index = 0;
        for(int x = 0; x < number_rows; ++x){
            for(int y = 0; y < number_columns; ++y){
                holder[x][y] = intArray[int_array_index];
                ++int_array_index;
            }
        } else{
            throw invalid_argument("The size should have an integer square root");
        }
    }
}
void matrix::set_value(int r, int c, double loc) {
    if(r < 0 || c < 0 || r > number_rows|| r > number_columns){
        throw invalid_argument("The rows number and columns number are negative and too large")
    }
    holder[r][c] = loc;
}
double matrix::get_value(int r, int c) const {
    if(r < 0 || c < 0 || r > number_rows||r > number_columns){
        throw invalid_argument("The number of row and column are negative and too large")
    }
    return holder[x][y];
}
void matrix::clear() {
    for(int x = 0; x < number_rows; ++x){
        for(int y = 0; y < number_rows; ++y){
            holder[x][y] == 0.0;
        }
    }
}
matrix::~matrix(){
    holder.clear();
}
ostream &operator<<(ostream &os, matrix &out_matrix){
    try{
        for(int row = 0; row < out_matrix.number_rows; rows++){
            for(int column = 0; column < out_matrix.number_columns; column++){
                os<<setw(10)<<left<<out_matrix.get_value(row,column);
            }
            os<<endl;
        }
    } catch(exception){
        fprintf(stderr, "except");
    }
    return os;
}
bool operator == (const matrix &mat1, const matrix &mat2){
    if(mat1.number_rows == mat2.number_rows && mat1.number_columns == mat2.number_columns){
        for(int x = 0; x < mat1.number_rows; x++){
            for(int y = 0; y < mat1.number_columns; x++){
                if(fab(mat1.hold[x][y] - mat2.hold[x][y]) > matrix::tolerance){
                    return false;
                }
            }
        }
        return true;
    }
}

