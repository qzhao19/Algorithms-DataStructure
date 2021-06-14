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
    Matrix(int nrows_, int ncols_);
    Matrix(int nrows_, int ncols_, double val);

    virtual ~Matrix();


};




#endif /*MATRIX_H_*/