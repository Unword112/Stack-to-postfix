#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_

#include "LinkedList.h"

class LinkedStack : public LinkedList
{
public:
    LinkedStack();
    //~LinkedStack();

    void push(int e);
    int pop();
    int top();

    void infixToPostfix(string infix);
    int precedence(char c);

    void SwapTwoTop();

};

#endif