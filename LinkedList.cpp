#include "LinkedList.h"

LinkedList::LinkedList()
{
    ChainNode *p = new ChainNode;
    curSize = 0;
    firstNode = p;
}

LinkedList::~LinkedList()
{
    ChainNode *p = firstNode;
    
    for(int i = 0; p != NULL; i++){
        ChainNode *n = p->next;
        delete p;
        p = n;
    }
}

void LinkedList::randList(int size)
{
    for (int i = 0; i < size; i++) add(i, rand() % 100);
}

int LinkedList::size()
{
    return curSize;
}

int LinkedList::indexOf(float e)
{
    ChainNode *p = firstNode->next;
    
    int index = 0;
    while(p != NULL){
        if(p->element == e) return index;
        //else if(p->element != e) return -1;
        p = p->next;
        index++;
    }
    return -1;
}

int LinkedList::get(int i)
{
    ChainNode *p = firstNode->next;

    int index = 0;
    while (p != NULL) {
            if(index == i) return p->element;
            p = p->next;
            index++;
    }

    return -1;
}

void LinkedList::set(int i, float e)
{
    ChainNode *p = firstNode->next;

    int index = 0;

    while(p != NULL){
        if(index == i){
            p->element = e;
            return;
        }
        p = p->next;
        index++;
    }
}

float LinkedList::remove(int i)
{
    ChainNode *p = firstNode;

    for(int j = 0; j < i; j++) p = p->next;
    
    ChainNode *q = p->next;
    ChainNode *r = p->next->next;

    float temp = q->element;
    delete q;
    p->next = r;
    curSize--;

    return temp;
}

void LinkedList::add(int i, float e)
{
    ChainNode *p = firstNode;
    
    if(i < 0) {
        cout << "Lower bound" << endl;
        i = 0;
    } else if(i > curSize) {
        cout << "Upper bound" << endl;
        i = curSize;
    }
    
    for(int j = 0; j < i; j++) p = p->next;
    
    ChainNode *new_node = new ChainNode(e);

    new_node->next = p->next;
    p->next = new_node;
    curSize++;
}

void LinkedList::clear()
{
    ChainNode *p = firstNode->next;
    
    for(int i = 0; p != NULL; i++){
        ChainNode *n = p->next;
        delete p;
        p = n;
    }
    firstNode->next = NULL;
    curSize = 0;
}

bool LinkedList::isEmpty()
{
    return curSize == 0;
}

void LinkedList::oddNumber()
{
    ChainNode *p = firstNode->next;

    cout << "Odd Number : ";
    for(int i = 0; p != NULL && i < curSize; i++){
        int temp = p->element;

        if(temp % 2 == 1) cout << temp << ", ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::evenNumber()
{
    ChainNode *p = firstNode->next;

    cout << "Even Number : ";
    for(int i = 0; p != NULL && i < curSize; i++){
        int temp = p->element;

        if(temp %  2 == 0) cout << temp;
        p = p->next;
    }
    cout << endl;
}

void LinkedList::sum()
{
    ChainNode *p = firstNode;

    int sum = 0;
    for(int i = 0; p != NULL && i <= curSize; i++){
        sum = sum + p->element;
        p = p->next;
    }
    cout << sum << endl;
}

void LinkedList::mean()
{
    ChainNode *p = firstNode;

    float sum = 0;
    for(int i = 0; p != NULL && i <= curSize; i++){
        sum = sum + p->element;
        p = p->next;
    }
    cout << sum/curSize << endl;
}

void LinkedList::sort()
{
    ChainNode *cur1 = firstNode;
    ChainNode *cur2 = firstNode;

    for (int i = 0; i < curSize; i++) {
        for (int j = 0; j < curSize - 1; j++) {
            if (cur1->element < cur2->element) {
                int temp = cur1->element;
                cur1->element = cur2->element;
                cur2->element = temp;

            }
            cur2 = cur2->next;
        }
         cur2 = firstNode;
         cur1 = firstNode->next;
         for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
         }
    }
}

void LinkedList::display()
{
    ChainNode *p = firstNode->next;

    cout << "L : [";
    for(int i = 0; i < curSize; i++){
        cout << p->element;
        if(i < curSize - 1) cout << ", ";
        p = p->next;
    }
    cout << " ] N : " << curSize << endl;
}
