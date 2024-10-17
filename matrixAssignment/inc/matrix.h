#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    int matrixRows, matrixColumns;
    double **matrix;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    void inputMatrix();
    void displayMatrix() const;
    Matrix operator+(Matrix const &matrix2) const;
    Matrix operator*(Matrix const &matrix2) const;
};

#endif