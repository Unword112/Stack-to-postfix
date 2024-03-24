#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include "ChainNode.h"

using namespace std;

class LinkedList {
    private:
        int curSize;
        ChainNode *firstNode;
        
    public:
        LinkedList();
        ~LinkedList();

        void randList(int size);
        
        int size();
        int indexOf(float e);
        int get(int i);
        void set(int i, float e);
        float remove(int i);
        void add(int i, float e);
        void clear();

        bool isEmpty();

        void oddNumber();
        void evenNumber();
        void sum();
        void mean();
        void sort();
        
        void display();
};

#endif