/***
  @file: Tester.cpp
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: Implementation file of Tester class
 ***/

#include "Tester.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Calculator.h"

using namespace std;

Tester::Tester(string fileName)
{
    testCasesFilename = fileName;
} /* end of Tester()*/

Tester::~Tester()
{
} /* end of ~Tester()*/

void Tester::runTests(bool detailed)
{
    vector<row> data = readFile(testCasesFilename);
    int total = data.size();
    int passed = 0;

    for (int i = 0; i < total; i++)
    {
        row r = data[i];
        string expression = r.expression;
        int expected = r.answer;

        // Change the final arg to true for detailed output
        if (testExpression(c, expression, expected, detailed))
            passed++;
    }
    cout << "Passed " << passed << " of " << total << " tests." << endl;
} /* end of runTests()*/

bool Tester::testExpression(Calculator &c, string &expression, int &expected, bool detailed)
{
    int actual = c.runCalc(expression);
    bool passed = actual == expected;
    if (detailed && !passed)
    {
        cout << "--- Opss! Error! --- " << endl;
        cout << expression << " = " << expected << " -> got: " << actual << endl;
    }
    else if (detailed)
        cout << expression << " = " << actual << " : " << expected << endl;

    return passed;
} /* end of testExpression()*/

vector<row> Tester::readFile(string path)
{
    vector<row> table;
    row currRow;
    string line, item;

    fstream file(path, ios::in);

    if (file.is_open())
    {
        int row = 0;
        while (getline(file, line))
        {
            stringstream str(line);
            if (row > 0) // skip header row
            {
                int col = 0;
                while (getline(str, item, ','))
                {
                    if (col == 0)
                        currRow.expression = item;
                    else
                        currRow.answer = stoi(item);
                    col++;
                }
                table.push_back(currRow);
            }
            row++;
        }
    }
    else
        cout << "Could not open file." << endl;

    return table;
} /* end of readFile()*/