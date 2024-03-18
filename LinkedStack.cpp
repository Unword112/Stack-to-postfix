#include "LinkedStack.h"

using namespace std;

LinkedStack::LinkedStack() : LinkedList()
{
    
}

void LinkedStack::push(int e)
{
    add(0, e);
}

int LinkedStack::pop()
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
    display(); // แสดง List หลัง Swap
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 0;
        case '*':
        case '/': return 1;
        case '^': return 2;
        default: return -1; // ให้ส่งค่าที่ไม่ได้ใช้เพื่อแสดงข้อผิดพลาด
    }
}

void infixToPostfix(string infix){
        LinkedStack stack;
        string postfix = "";
        
        for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c >= '0' && c <= '9') 
                postfix += c;
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (!stack.isEmpty() && precedence(c) <= precedence(stack.top())) {
                postfix += stack.pop();
                }
                stack.push(c);
        } else if (c == '(') {
                stack.push(c);
        } else if (c == ')') {
                while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.pop();
                }
                stack.pop(); // นำวงเล็บเปิดออกจาก Stack
        }
        }

        while (!stack.isEmpty()) {
        postfix += stack.pop();
        }

    cout << postfix;
}
