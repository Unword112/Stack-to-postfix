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
