/***
  @file Stack.h
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: header file for Stack class
 ***/
#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stddef.h>

template <class T>
class Stack
{
private:
    node<T> *top;
    int length; // size of the stack

public:
    // Default constructor
    Stack();
    // Copy constructor
    Stack(const Stack<T> &);
    // Destructor
    ~Stack();
    // copy() copies the stack
    void copy(const Stack<T> &);
    // destroy() destroies the stack
    void destroy();
    // Operator= overload
    const Stack<T> &operator=(const Stack<T> &);
    // isEmpty() returns true if there are no items otherwise false
    bool isEmpty() const;
    // push() adds an item to the top of the stack
    void push(const T &);
    // Pop() deletes the top item on the stack
    void pop();
    // Top() returns the top element of the stack without removing it by reassiging the reference parameter with the top item
    void Top(T &);
    // returns the size of the stack
    int size();
    // peek() return the last item on top of stack
    T peek();
};

#endif