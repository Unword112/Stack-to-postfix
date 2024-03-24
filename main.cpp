#include <iostream>
#include "LinkedStack.h"
#include "math.h"
#include <iomanip> 

using namespace std;

int main() {
        cout << "Work: Stack Appication" << endl;
        cout << "66066780 Nathakith Baosalee" << endl;

        LinkedStack stack;

        cout << fixed << setprecision(2);
        string infix_1 = "2^((1+4/2)^2)";
        string infix_2 = "2^((1+4)/2)";
        cout << "Infix 1 : " << infix_1 << endl;
        cout << "Infix 2 : " << infix_2 << endl;
        cout << "Postfix 1 Form Is: " << stack.infixToPostfix(infix_1) << endl;
        cout << "Postfix 2 Form Is: " << stack.infixToPostfix(infix_2) << endl;

        cout << "Calculate Postfix: " << stack.calPostfix(stack.infixToPostfix(infix_1)) << endl;
        cout << "Calculate Postfix: " << stack.calPostfix(stack.infixToPostfix(infix_2)) << endl;
    return 0;
}