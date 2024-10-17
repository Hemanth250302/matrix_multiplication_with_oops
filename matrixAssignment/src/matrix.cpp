#include <iostream>
#include "matrix.h"
#include "inputValidation.h"

Matrix::Matrix(int rows, int cols)
    : matrixRows{rows}, matrixColumns{cols}
{
    matrix = new double *[rows];
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        matrix[rowIndex] = new double[cols]{0};
    }
}

Matrix::~Matrix()
{
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        delete[] matrix[rowIndex];
    }
    delete[] matrix;
}

void Matrix::inputMatrix()
{
    float input;

    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < matrixColumns; columnIndex++)
        {
            std::cout << "matrix" << "[" << rowIndex << "]" << "[" << columnIndex << "]" << ": ";

            matrix[rowIndex][columnIndex] = floatInputValidation(input);
        }
    }
}

void Matrix::displayMatrix() const
{
    for (int rowIndex = 0; rowIndex < matrixRows; ++rowIndex)
    {
        for (int columnIndex = 0; columnIndex < matrixColumns; ++columnIndex)
        {
            std::cout << matrix[rowIndex][columnIndex] << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::operator+(Matrix const &matrix2) const
{
    Matrix matrix3(matrixRows, matrixColumns);
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < matrixColumns; columnIndex++)
        {
            matrix3.matrix[rowIndex][columnIndex] = matrix[rowIndex][columnIndex] + matrix2.matrix[rowIndex][columnIndex];
        }
    }
    return matrix3;
}

Matrix Matrix::operator*(Matrix const &matrix2) const
{
    Matrix matrix3(matrixRows, matrix2.matrixColumns);

    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < matrix2.matrixColumns; columnIndex++)
        {
            matrix3.matrix[rowIndex][columnIndex] = 0;
            for (int commonIndex = 0; commonIndex < matrixColumns; commonIndex++)
            {
                matrix3.matrix[rowIndex][columnIndex] += matrix[rowIndex][commonIndex] * matrix2.matrix[commonIndex][columnIndex];
            }
        }
    }
    return matrix3;
}