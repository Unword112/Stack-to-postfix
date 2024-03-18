#include <iostream>
#include "LinkedStack.h"

using namespace std;

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