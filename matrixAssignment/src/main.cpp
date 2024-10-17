#include "utils.h"

int main()
{
    char choice;
    while (true)
    {
        displayMenu();
        choice = getChoice();
        handleChoiceOperation(choice);
    }
}
