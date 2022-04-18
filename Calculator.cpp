/***

  @file: Calculator.cpp
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: Implementation file for Calculator class

***/

#include "Calculator.h"
#include <cctype>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>

using namespace std;

Calculator::Calculator() {}

Calculator::~Calculator() {}

int Calculator::runCalc(const string &input)
{
    handleInput(input);
    operateTillEmpty();

    int result;
    digits.Top(result);
    digits.pop();

    return result;
} /*end of runCalc()*/

void Calculator::handleInput(const string &input)
{
    // remove spaces from input
    string strippedInput = removeSpace(input);

    // use a string stream to read from the string
    stringstream strStream;
    strStream.str(strippedInput);

    bool nextNumFlag = true;
    bool nextOpFlag = false;

    int val;
    char op;

    while (strStream.peek() != EOF)
    {
        // if strStream is a digit number using isdigit()
        if (isdigit(strStream.peek()))
        {
            strStream >> val;
            handleDigits(val);
            nextNumFlag = false;
            // adds * to op stack if a digit is followed by an open paren when * doesn't exsit
            if (strStream.peek() == '(')
                handleOp('*');
        }

        // else if (isBalanced(strippedInput) && ops.isEmpty())
        //    handleOp('*');

        // Handle a minus/plus sign when we expect a number.
        else if (nextNumFlag &&
                 (strStream.peek() == '-' || strStream.peek() == '+'))
        {
            // a) an odd case like -(3+4)+5 or +(3+4)-1
            // b) a negative/positive number case
            // save our current position, then jump ahead one character to see if it is open (
            char currentSymbol = strStream.peek();
            int currentPos = strStream.tellg();

            strStream.seekg(currentPos + 1);

            if (strStream.peek() == '(')
            {
                // handle -(expression) as -1 * (expression)
                // handle +(expression) as 1 * (expression)
                // Leave our position in the stringstream where it is.
                // The next iteration of this loop will handle the `(`.

                // if current symbol is - then assign -1 to preValue else assign 1
                int preValue = currentSymbol == '-' ? -1 : 1;

                handleDigits(preValue);
                // then push multiplication to handle the sign of preValue
                handleOp('*');
            }
            else
            {
                // negative number case: Go back to current position and add val.
                strStream.seekg(currentPos);
                strStream >> val;
                handleDigits(val);
            }
            nextNumFlag = false;
        }

        else
        {
            // The next symbol is not a number; handle as an operator
            strStream >> op;
            handleOp(op);
            if (op == ')')
                nextNumFlag =
                    false; // right parentheses must be followed by an operator
            else
                nextNumFlag = true;
        }
    }
} /*end of handleInput()*/

string Calculator::removeSpace(const string &input)
{
    string strippedStr = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
            strippedStr += input[i];
    }
    return strippedStr;

} /*end of removeSpace()*/

void Calculator::handleDigits(const int &value)
{
    digits.push(value);
} /*end of handleDigits()*/

void Calculator::handleOp(const char &op)
{
    char currTop = ' ';
    ops.Top(currTop);

    if (op == ')') // if found closed parentheses
        calcParentheses();
    else if (ops.isEmpty() || op == '(' || currTop == '(')
        ops.push(op);
    else if (precedence(currTop) >= precedence(op))
        calcHigherPrece(op);
    else
        ops.push(op);
} /*end of handleOp()*/

void Calculator::calcParentheses()
{
    char currTop = ' ';
    ops.Top(currTop);

    while (currTop != '(')
    {
        calculate();
        ops.Top(currTop);
    }
    ops.pop(); // remove the left parentheses
} /*end of calcParentheses()*/

void Calculator::calcHigherPrece(const char &op)
{
    char currTop = ' ';
    ops.Top(currTop);
    while (!ops.isEmpty() && precedence(currTop) >= precedence(op))
    {
        calculate();
        ops.Top(currTop);
    }
    ops.push(op);
} /*end of calcHigherPrece()*/

void Calculator::operateTillEmpty()
{
    while (!ops.isEmpty())
        calculate();
} /*end of operateTillEmpty()*/

int Calculator::precedence(const char &op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
} /*end of precedence()*/

void Calculator::calculate()
{
    // Remove top 2 values and top operator
    int right = getTopDigits();
    int left = getTopDigits();
    char op = getTopOp();

    // Do the calculation
    int result;
    switch (op)
    {
    case '^':
        if (right < 0)
            result = 0; // for ints: 1 / left^right = 0
        else
        {
            result = 1;
            for (int i = 0; i < right; i++)
                result *= left;
        }
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = left / right;
        break;
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    default:
        cout << "Invalid operator" << endl;
        break;
    }

    // Push the result back to the digits stack
    digits.push(result);
} /*end of doNextCalculation()*/

int Calculator::getTopDigits()
{
    int val;
    digits.Top(val);
    digits.pop();

    return val;
} /*end of getTopDigits()*/

char Calculator::getTopOp()
{
    char op = ' ';
    ops.Top(op);
    ops.pop();

    return op;
} /*end of getTopOp()*/

// bool Calculator::isBalanced (const string &input) {

//   char x = ' ';

//   for (int i = 0; i < input.size(); i++) {
//     if (input[i] == '(') {
//       parenStack.push(input[i]);
//       continue;
//     }
//     if (parenStack.isEmpty())
//       return false;

//     switch (input[i]) {
//     case ')':
//       parenStack.Top(x);
//       parenStack.pop();
//       break;
//     }
//   }
//   return (parenStack.isEmpty());
// }