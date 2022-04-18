/**
  @file: Tester.cpp
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: Header file of Tester class
 ***/

#ifndef TESTER_H
#define TESTER_H

#include "Calculator.h"
#include "row.h"
#include <vector>
#include <string>

using namespace std;

class Tester
{
private:
    Calculator c;
    string testCasesFilename;
    vector<row> readFile(string);
    bool testExpression(Calculator &, string &, int &, bool);

public:
    Tester(string = "testCases.txt");
    ~Tester();
    void runTests(bool);
};
#endif