#include "matrix.hpp"
#include <iostream>

using namespace std;

void Matrix::initMat(){
    mat = new double *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        mat[i] = new double [n_cols];
    }
}


Matrix::Matrix (int n_rows_, int n_cols_) {
    n_cols = n_rows_;
    n_cols = n_cols_;

    initMat();

    for(int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = 0;
        }
    }
}


Matrix::Matrix (int n_rows_, int n_cols_, double val) {
    n_cols = n_rows_;
    n_cols = n_cols_;

    initMat();
    for(int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = val;
        }
    }
}


Matrix::~Matrix () {
    for (int i = 0; i < n_rows; i++) {
        delete[] mat[i];
    }

    delete[] mat;

}


Matrix& Matrix::operator=(const Matrix &M){
    if (this == &M){
        return *this;
    }

    if (n_rows != M.n_rows || n_cols != M.n_cols){
        for (int i = 0; i < n_rows; i++){
            delete[] mat[i];
        }
        delete[] mat;

        n_rows = M.n_rows;
        n_cols = M.n_cols;
        initMat();
    }

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = M.mat[i][j];
        }
    }

    return *this;
}


Matrix& 





