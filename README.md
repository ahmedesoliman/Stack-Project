# Arithmetic Evaluator

A program that uses stacks to evaluate an arithmetic expression in infix notation without converting it into postfix notation.

The program takes an input as s numeric expression in infix notation, such as 3+4\*2, and outputs the result.

Arithmetic_Evaluator is a simple console application built using C++ that evaluates arithmetic expressions. The application supports basic arithmetic operations such as addition, subtraction, multiplication, and division, as well as parentheses to group operations. Arithmetic_Evaluator provides an easy-to-use and efficient solution for evaluating arithmetic expressions programmatically.

- 1.  Operators are +, -, \*, /, ^
- 2.  The expression should be formed correctly so that each operation has two arguments.
- 3.  The expression can have parenthesis, for example: 3\*(4-2)+6.
- 4.  The expression can have negative numbers.
- 5.  The expression can have spaces in it, for example: 3 \* (4-2) +6.

#### The expression can contain multiple operations and parentheses but must be valid and balanced (same number of opening and closing parentheses).

- The operators are binary meaning there must be left & right value for each side.
- Good: 2 + ((3 \* 4)^(1 -5)) // Good example
- Bad: 3 + (4 // parentheses not balanced
- Bad: 3 + (1 +) // not enough numbers

# Calculator.cpp

- The Calculator uses stacks to evaluate an arithmetic expression in infix notation without converting it into postfix notation.

- It can compute a string of mathematical operations on integers only (including negative integers).

#### The calculator follows PEMDAS rules (order of opertions) and can handle the following symbols:

- Operators order: ^, \*, /, +, -
- P - Parentheses: ( )
- E - Exponents: Power ^ of positive integers
- MD - Multiplication and Division (left to right) (× and ÷)
- AS - Addition and Subtraction (left to right) (+ and -)
