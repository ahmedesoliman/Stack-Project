/**
  @file Stack.cpp
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief Implementation file of Stack class
 */
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    top = NULL;
    length = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T> &other)
{
    copy(other);
}

template <class T>
const Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <class T>
Stack<T>::~Stack()
{
    destroy();
}

template <class T>
void Stack<T>::copy(const Stack<T> &other)
{
    if (other.isEmpty())
        top = NULL;
    else
    {
        // copy the top node
        node<T> *p = other.top;
        top = new node<T>;
        top->info = p->info;
        top->next = NULL;

        // copy rest of nodes
        node<T> *temp = top;
        p = p->next;
        while (p != NULL)
        {
            // copy node
            node<T> *newNode = new node<T>;
            newNode->info = p->info;
            newNode->next = NULL;

            // attach node to temp
            temp->next = newNode;

            // advance pointers
            temp = temp->next;
            p = p->next;
        }
    }
}

template <class T>
void Stack<T>::destroy()
{
    node<T> *p;
    while (top != NULL)
    {
        p = top;
        top = top->next;
        p->next = NULL;
        delete p;
    }
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return top == NULL;
}

template <class T>
void Stack<T>::push(const T &item)
{
    node<T> *newNode = new node<T>;
    newNode->info = item;
    newNode->next = top;
    top = newNode;
    length++;
}

template <class T>
void Stack<T>::Top(T &item)
{
    if (!isEmpty())
        item = top->info;
}

template <class T>
void Stack<T>::pop()
{
    if (!isEmpty())
    {
        node<T> *p = top;
        top = top->next;
        p->next = NULL;
        delete p;
        length--;
    }
}

template <class T>
int Stack<T>::size()
{

    return length;
}

template <class T>
T Stack<T>::peek()
{
    if (!isEmpty())
        return top->info;
}