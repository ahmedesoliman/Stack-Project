/***
  @file: node.h
  @author: Ahmed Soliman
  @date: 03/20/2020
  @brief: Header file for node struct used in linked list stack implementation
 ***/

#ifndef NODE_H
#define NODE_H
template <class T>
struct node
{
    T info;
    node *next;
};

#endif