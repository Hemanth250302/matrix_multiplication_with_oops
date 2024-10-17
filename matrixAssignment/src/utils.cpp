
#include "inputValidation.h"
#include "matrix.h"
#include "utils.h"
#include <iostream>
#include <limits>

void displayMenu()
{
    std::cout << "Select an Operation" << '\n';
    std::cout << "a-addition" << '\n';
    std::cout << "m-multiplication" << '\n';
    std::cout << "e-exit" << '\n';
}

char getChoice()
{
    char result;
    std::cout << "enter your choice" << '\n';
    char choice;
    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!validateChoice(choice) || std::cin.gcount() > 1)
    {
        std::cout << "invalid choice!!! try again " << '\n';
        return getChoice();
    }
    else if (choice == 'e')
    {
        std::cout << "exiting from the program";
        exit(1);
    }

    else
        result = choice;
    return result;
}

void PerformOperation(int matrix1rows, int matrix1columns, int matrix2rows, int matrix2columns, std::string operation)
{
    Matrix matrix1(matrix1rows, matrix1columns);
    std::cout << "Enter the elements of matrix1" << '\n';
    matrix1.inputMatrix();
    matrix1.displayMatrix();
    std::cout << '\n';

    Matrix matrix2(matrix2rows, matrix2columns);
    std::cout << "Enter the elements of matrix2" << '\n';
    matrix2.inputMatrix();
    matrix2.displayMatrix();
    std::cout << '\n';

    if (operation == "addition")
    {
        Matrix matrix3 = matrix1 + matrix2;
        std::cout << "resultant matrix:" << '\n';
        matrix3.displayMatrix();
    }
    else
    {
        Matrix matrix3 = matrix1 * matrix2;
        std::cout << "resultant matrix:" << '\n';
        matrix3.displayMatrix();
    }
}

void getMatrixDimensions(int &matrix1rows, int &matrix1columns, int &matrix2rows, int &matrix2columns)
{

    std::cout << "Enter the no of rows for matrix1:";

    matrix1rows = integerInputValidation();

    std::cout << "Enter the no of cols for matrix1:" << '\n';

    matrix1columns = integerInputValidation();

    std::cout << "Enter the no of rows for matrix2:" << '\n';

    matrix2rows = integerInputValidation();

    std::cout << "Enter the no of cols for matrix2:" << '\n';

    matrix2columns = integerInputValidation();
}

void handleChoiceOperation(char choice)
{
    int matrix1rows, matrix1columns, matrix2rows, matrix2columns;

    getMatrixDimensions(matrix1rows, matrix1columns, matrix2rows, matrix2columns);
    if (choice == 'a')
    {
        if (matrix1rows == matrix2rows && matrix1columns == matrix2columns)
        {
            PerformOperation(matrix1rows, matrix1columns, matrix2rows, matrix2columns, "addition");
        }
        else
        {
            std::cout << "dimenstion do not match for Addition" << '\n';
        }
    }

    else
    {
        if (matrix1columns == matrix2rows)
        {
            PerformOperation(matrix1rows, matrix1columns, matrix2rows, matrix2columns, "multiplication");
        }
        else
        {
            std::cout << "dimenstion do not match for Multiplication" << '\n';
        }
    }
}