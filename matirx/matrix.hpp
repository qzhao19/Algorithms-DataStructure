#ifndef MATRIX_H_
#define MATRIX_H_

#include <cmath>
#include <iostream>
#include <stdlib.h>

class Matrix {

private:
    int n_rows;
    int n_cols;
    double **mat;

    void initMat();

public:
    Matrix(int n_rows_, int n_cols_);
    Matrix(int n_rows_, int n_cols_, double val);

    virtual ~Matrix();

    Matrix& operator=(const Matrix& M);
    Matrix& operator=(double *val);
    Matrix& operator+=(const Matrix &M);
    Matrix& operator-=(const Matrix &M);
    Matrix& operator*=(const Matrix &M);
    Matrix& operator*(const Matrix &M) const;

    static Matrix Hadamard(const Matrix &A, const Matrix & B);

    static Matrix Solve(const Matrix &A, const Matrix &b);

    void show();

    void swapRows(int x, int y);

    double det();


};




#endif /*MATRIX_H_*/