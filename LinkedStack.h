#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_

#include "LinkedList.h"

class LinkedStack : public LinkedList
{
public:
    LinkedStack();
    //~LinkedStack();

    void push(float e);
    float pop();
    int top();

    string infixToPostfix(string infix);
    int precedence(char c);
    float calPostfix(string postfix);

    void check();

    void SwapTwoTop();

};

#endif