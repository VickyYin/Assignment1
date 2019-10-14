//
// Created by Yaqi Yin on 2019-10-04.
//
#ifndef ASS1_MATRIX_HPP
#define ASS1_MATRIX_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

using namespace std;
class matrix {
private:
    int number_rows;
    int number_cols;
    vector<vector<double>> holder;
public:
    static const double tolerance;
    matrix();//init a square 1x1 matrix that contains a 0.0
    matrix(int n);//creates a square nxn matrix where n>0
    matrix(int r, int c);//creates a matrix with r rows and c columns that contain 0.0. r,c >0
    matrix(double intArray[], int size);//n=n^2
    matrix(const matrix& copy);
    ~matrix();
    void set_value(int r, int c, double loc);//int > 0
    double get_value(int r, int c)const;//int > 0;
    void clear();//sets all values in matrix to 0
    void swap(matrix& matrix1, matrix& matrix2);
    friend ostream & operator << (ostream &os, matrix & out_matrix);
    friend bool operator != (const matrix& mat1, const matrix & mat2);
    friend bool operator == (const matrix& mat1, const matrix & mat2);
    matrix& operator ++ ();
    matrix& operator ++ (int);
    matrix& operator -- ();
    matrix& operator -- (int);
    matrix& operator =(matrix mat2);
    matrix& operator += (const matrix& mat2);
    matrix& operator -= (const matrix& mat2);
    friend matrix operator +(matrix mat1, const matrix& mat2);
    friend matrix operator -(matrix mat1, const matrix& mat2);
    friend matrix operator *(matrix mat1, const matrix& mat2);
    matrix& operator *=(const matrix& mat2);
    vector<vector<double>>generate_matrix(int r, int c);
    int get_number_rows() const;
    int get_number_cols() const;





};
#endif //ASSIGNMENT1_MATRIX_HPP