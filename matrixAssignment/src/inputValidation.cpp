#include <iostream>
#include <limits>
#include "inputValidation.h"

bool validate()
{
    bool isValid = true;
    if (std::cin.fail())
    {
        std::cout << "invalid input enter again" << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.gcount() > 1)
    {
        std::cout << "invalid input enter again" << '\n';
        isValid = false;
    }
    return isValid;
}

int integerInputValidation()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (!validate())
        {
            continue;
        }
        if (input <= 0)
        {
            std::cout << "invalid input enter again" << '\n';
            continue;
        }

        break;
    }

    return input;
}

float floatInputValidation(float input)
{

    while (true)
    {
        std::cin >> input;

        if (!validate())
        {
            continue;
        }

        break;
    }

    return input;
}

bool validateChoice(char choice)
{
    bool isValid = false;
    if (choice == 'a' || choice == 'm' || choice == 'e')
    {

        isValid = true;
    }
    return isValid;
}