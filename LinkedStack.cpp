#include "LinkedStack.h"
#include "math.h"

using namespace std;

LinkedStack::LinkedStack() : LinkedList()
{
    
}

void LinkedStack::push(float e)
{
    add(0, e);
}

float LinkedStack::pop()
{
    return remove(0);
}

int LinkedStack::top()
{
    return get(0);
}

void LinkedStack::SwapTwoTop()
{
    cout << "Before SwapTwoTop() - ";
    display(); // แสดง List ก่อน Swap

    if (size() >= 2) {
        int top1 = get(0);
        int top2 = get(1);

        remove(0);
        set(0, top2);
        add(0, top1);
    } else {
        cout << "Error: Not enough elements in the stack to perform the swap." << endl;
    }

    cout << "After SwapTwoTop() - ";
    display(); 
}

int LinkedStack::precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 0;
        case '*':
        case '/': return 1;
        case '^': return 2;
        default: return -1;
    }
}

string LinkedStack::infixToPostfix(string infix){
        string postfix = "";

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if (isdigit(c)) { 
                postfix += c;
            } else if (c == '(') {
                push(c);
            } else if (c == ')') {
                while (!isEmpty() && top() != '(') {
                    postfix += pop();
                }
                pop(); 
            } else { 
                while (!isEmpty() && precedence(c) <= precedence(top())) {
                    postfix += pop();
                }
                push(c);
            }
        }

        while (!isEmpty()) {
            postfix += pop();
        }

    return postfix;
}

float LinkedStack::calPostfix(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(c - '0');
            display();
        } else {
            float operand2 = pop(); //2
            float operand1 = pop(); //2.5
            switch (c) {
                case '+':
                    push(operand1 + operand2);
                    display();
                    break;
                case '-':
                    push(operand1 - operand2);
                    display();
                    break;
                case '*':
                    push(operand1 * operand2);
                    display();
                    break;
                case '/':
                    push(operand1 / operand2);
                    display();
                    break;
                case '^':
                    push(pow(operand2, operand1));
                    display();
                    break;
                default : return -1;
            }
        }
    }

    return pop();
}

void LinkedStack::check(){
    push(2.5);
    push(2);

    float operand2 = pop();
    float operand1 = pop();

    cout << operand2 << endl;
    cout << operand1 <<endl;
    cout << pow(operand1, operand2) << endl;
} 