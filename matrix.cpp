//
// Created by Yaqi Yin on 2019-10-04.
//
#include "matrix.hpp"
const double matrix::tolerance = 0.00001;
matrix::matrix(): number_rows(1), number_cols(1){
    holder = generate_matrix(number_rows, number_cols);
    clear();
}

matrix::matrix(const matrix &copy) {
    number_rows = copy.number_rows;
    number_cols = copy.number_cols;
    holder = generate_matrix(number_rows,number_cols);
    for (int x = 0; x < number_rows; ++x) {
        for (int y = 0; y < number_cols; ++y) {
            holder[x][y] = copy.holder[x][y];
        }
    }
}

matrix::matrix(int n):number_rows(n), number_cols(n) {
    if(n<=0) {
        throw invalid_argument("n is not a positive value");
    }
    holder = generate_matrix(number_rows, number_cols);
    clear();
}

matrix::matrix(int r, int c): number_rows(r), number_cols(c) {
    if(r<=0 || c<=0) {
        throw invalid_argument("r or c is not a positive number");
    }
    holder = generate_matrix(number_rows, number_cols);
    clear();
}

matrix::matrix(double int_array[], int size) {
    int root = sqrt(size);
    if(root * root == size) {
        number_rows = root;
        number_cols = root;
        holder = generate_matrix(number_rows, number_cols);
        int int_array_index = 0;
        for(int x = 0; x < number_rows; ++x) {
            for(int y = 0; y < number_cols; ++y) {
                holder[x][y] = int_array[int_array_index];
                ++int_array_index;
            }
        }
    } else {
        throw invalid_argument("The size of the array does not have an integer square root");
    }
}

void matrix::set_value(int r, int c, double loc) {
    if (r < 0 || c < 0 || r > number_rows || c > number_cols) {
        throw invalid_argument("integers are negative or too large.");
    }
    holder[r][c] = loc;
}

double matrix::get_value(int r, int c) const {
    if (r < 0 || c < 0 || r > number_rows || c > number_cols) {
        throw invalid_argument("integers are negative or too large.");
    }
    return holder[r][c];
}

void matrix::clear() {
    for(int x = 0; x < number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            holder[x][y]=0.0;
        }
    }
}

matrix::~matrix() {
    holder.clear();
}

ostream &operator<<(ostream &os, matrix &out_matrix) {
    try {
        for(int rows = 0; rows < out_matrix.number_rows; rows++) {
            for(int cols = 0; cols < out_matrix.number_cols; cols++) {
                os<<setw(10)<<left<<out_matrix.get_value(rows,cols);
            }
            os<<endl;
        }
    } catch(exception) {
        fprintf(stderr, "except");
    }
    return os;
}

bool operator==(const matrix &mat1, const matrix &mat2) { // if the matrices are the same
    if (mat1.number_rows == mat2.number_rows && mat1.number_cols == mat2.number_cols) {
        for(int x = 0; x < mat1.number_rows; x++) {
            for(int y = 0; y < mat1.number_cols; y++) {
                if(fabs(mat1.holder[x][y] - mat2.holder[x][y])>matrix::tolerance) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const matrix &mat1, const matrix &mat2) {
    return !(mat1==mat2);
}

matrix& matrix::operator++() {
    for(int x = 0; x < number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            ++holder[x][y];
        }
    }
    return *this;
}

matrix& matrix::operator++(int) {
    for(int x = 0; x < number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            holder[x][y]++;
        }
    }
    return *this;
}

matrix& matrix::operator--() {
    for(int x = 0; x < number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            --holder[x][y];
        }
    }
    return *this;
}

matrix& matrix::operator--(int) {
    for(int x = 0; x < number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            holder[x][y]--;
        }
    }
    return *this;
}

void matrix::swap(matrix &mat1, matrix &mat2) {
    using std::swap;

    swap(mat1.number_rows, mat2.number_rows);
    swap(mat1.number_cols, mat2.number_cols);
    swap(mat1.holder, mat2.holder);

}

matrix& matrix::operator=(matrix mat2) {
    swap(*this,mat2);
    return *this;
}

matrix& matrix::operator+=(const matrix &mat2) {
    if(number_rows!=mat2.number_rows && number_cols!=mat2.number_cols) {
        throw invalid_argument("operands passed to the operator are not the same size.");
    }
    for(int x = 0; x <number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            holder[x][y]+=mat2.holder[x][y];
        }
    }
    return *this;
}

matrix& matrix::operator-=(const matrix &mat2) {
    if(number_rows!=mat2.number_rows && number_cols!=mat2.number_cols) {
        throw invalid_argument("operands passed to the operator are not the same size.");
    }
    for(int x = 0; x <number_rows; ++x) {
        for(int y = 0; y < number_cols; ++y) {
            holder[x][y]-=mat2.holder[x][y];
        }
    }
    return *this;
}

matrix operator +(matrix mat1, const matrix &mat2) {
    mat1+=mat2;
    return mat1;
}

matrix operator -(matrix mat1, const matrix &mat2) {
    mat1-=mat2;
    return mat1;
}

matrix& matrix::operator*=(const matrix &mat2) {
    if (number_cols!=mat2.number_rows) {
        throw invalid_argument("the number of columns of the first operand is not equal to the number of rows of the second operand");
    }
    matrix temp(number_rows, mat2.number_cols);
    for(int x = 0; x < temp.number_rows; ++x) {
        for(int y = 0; y < temp.number_cols; ++y) {
            for(int z = 0; z <number_cols; ++z) {
                double result = holder[x][z]*mat2.holder[z][y];
                temp.holder[x][y]+=result;
            }
        }
    }
    swap(*this, temp);
    return *this;
}

matrix operator *(matrix mat1, const matrix &mat2) {
    mat1*=mat2;
    return mat1;
}

int matrix::get_number_cols() const {
    return number_cols;
}

int matrix::get_number_rows() const {
    return number_rows;
}






vector<vector<double>>matrix::generate_matrix(int r, int c) {
    vector<vector<double>> temp_matrix(r, vector<double>(c));
    return temp_matrix;
}