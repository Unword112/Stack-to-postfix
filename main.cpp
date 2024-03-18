#include <iostream>
#include "LinkedStack.h"

using namespace std;

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

int main() {
        cout << "Work: Stack Appication" << endl;
        cout << "66066780 Nathakith Baosalee" << endl;

        LinkedStack stack;

        string infix_1 = "2^(1+4/2)^2";
        string infix_2 = "2^((1+4)/2)";
        cout << "Infix 1 : " << infix_1 << endl;
        cout << "Infix 2 : " << infix_2 << endl;
        cout << "Postfix 1 Form Is: ";
        infixToPostfix(infix_1);
        cout << endl;
        cout << "Postfix 2 Form Is: ";
        infixToPostfix(infix_2);
        cout << endl;

    return 0;
}