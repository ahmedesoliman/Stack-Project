/***
  @file: Calculator.h
   @author: Ahmed Soliman
   @date: 03/20/2020
   @brief: Header file for Calculator class

 ***/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Stack.cpp"
#include <string>
#include <sstream>

using namespace std;

class Calculator
{
private:
  // digits is a stack of integers that holds the values used in the calculation
  Stack<int> digits;
  // ops is a stack of characters that holds the operators and non-numeric symbols
  Stack<char> ops;
  Stack<char> parenStack;

public:
  // constructor
  Calculator();
  // destructor
  ~Calculator();
  // runCalc() runs the calculator program and return int with the result
  int runCalc(const string &);

  // handleInput() cleans and processes the input string, handling all digits and op symbols in the string
  void handleInput(const string &);

  // handleDigits() carries out the logic and procedures for processing a number in the calculation
  void handleDigits(const int &);

  // handleOp() carries out the logic and procedures for processing an operator in the calculation
  void handleOp(const char &);

  // removeSpace() removes all whitespaces from the input string
  string removeSpace(const string &);

  // getTopValue() returns the top of the digits stack, It also pops that value from the stack.
  int getTopDigits();

  // getTopOp() returns the top of the operator stack. It also pops that operator from the stack.
  char getTopOp();

  // precedence() returns an integer representing the precedence of an operator in the order of operations
  int precedence(const char &);

  // calculate() removes the top operator and the top two digits, calculates the result, and pushes the result back onto the digits stack
  void calculate();

  // calcParentheses() is called when a closing parenthesis is reached. It will calculate the digits and ops on the stacks until it reaches the left parentheses.
  void calcParentheses();

  // operateTillEmpty() performs calculations until the operator stack is empty
  void operateTillEmpty();

  // calcHigherPrece() this function calculates all ops on the stack that have a greater or equal precedence than the op parameter
  void calcHigherPrece(const char &);

  // isBalanced() checks if a string has a balanced amount of parentheses
  bool isBalanced(const string &);
};
#endif