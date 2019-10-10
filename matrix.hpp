//
// Created by Yaqi Yin on 2019-10-04.
//
#include <iostream>
#include <vector>
#include <cmap>
#include <stdexcept>;
#include <iomanip>;
#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP


class matrix{
private:
    int number_rows;
    int number_columns;
    vector<vector<double>>holder;
public:
    static const double tolerance;
    matrix();
    matrix(int n);
    matrix(int r,int c);
    matrix(double intArray[],int size);
    matrix(const matrix& copy);
    void set_value(int r, int c, double loc);
    double get_value(int r, int c)const;
    void clear();
    ~matrix();
    void swap(matrix& matrix1, matrix& matrix2);
    friend ostream & operator <<(ostream &os, matrix & out_matrix);
    friend bool operator != (const matrix &mat1, const matrix & mat2);
    friend bool operator == (const matrix &mat1, const matrix & mat2);
    matirx& operator ++ ();
    matrix& operator ++ (int);
    matrix& operator --();
    matrix& operator --(int);
    matrix& operator = (matrix mat2);
    matrix& operator += (const matrix &mat2);
    matrix& operator -= (const matrix &mat2);
    friend matrix operator + (matrix mat1, const matrix& mat2);
    friend matirx operator - (matrix mat1, const matrix& mat2);
    friend matrix operator * (matrix mat1, const matrix& mat2);
    matrix& operator *=(const matrix& mat2);
    vector<vector<double>>generate_matrix(int r, int c);
    int get_number_rows = const;
    int get_number_columns = const;



};
#endif //ASSIGNMENT1_MATRIX_HPP