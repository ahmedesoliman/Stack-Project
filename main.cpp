/***
  @file main.cpp
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: Manual tester for Stack Calculator
 ***/

#include <iostream>
#include <string>
#include "Calculator.h"
#include "Tester.h"

using namespace std;

/*** function prototypes ***/
int printMenu();
void automatedTests();
void manualCalculator();

int main()
{
    int selection = printMenu();
    if (selection == 1)
        automatedTests();
    else if (selection == 2)
        manualCalculator();
}

int printMenu()
{
    string selection;

    cout << "Welcome to the calculator tester!" << endl;
    cout << "1) Run the automated tests" << endl;
    cout << "2) Use the calculator in the print menu" << endl;
    cout << "3) Exit" << endl;
    cout << "Please enter 1, 2 or 3: ";
    getline(cin, selection);

    return stoi(selection);
}

void automatedTests()
{
    char selection;

    cout << "Run tests with detailed output? (y/n) ";
    cin >> selection;

    bool detailed = selection == 'y';

    Tester t;
    t.runTests(detailed);
}

void manualCalculator()
{
    Calculator calc;

    cout << " ***** ARTHMETIC CALCULATOR *****" << endl;

    string playAgain = "y";
    while (playAgain == "y")
    {
        string input;
        cout << endl;
        cout << "Type in integers only math problem" << endl;
        cout << "Operations Allowed: (+) (-) (*) (/) (^)" << endl;
        cout << "Using parenthesis: Allowed." << endl;
        cout << "Enter the arithmetic expression: ";
        getline(cin, input);
        // bool balance = calc.isBalanced(input);
        // if (balance)
        //   cout << "expression is balanced!" << "\n" ;
        int result = calc.runCalc(input);
        cout << "The answer is: " << result << endl;

        cout << "Do another calculation? (y/n) ";
        getline(cin, playAgain);
    }
}