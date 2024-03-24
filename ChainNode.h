#ifndef _CHAINNODE_H_
#define _CHAINNODE_H_

#include <iostream>

using namespace std;

class ChainNode {
    public:
        float element;
        ChainNode *next;
        
        ChainNode(float e = 0, ChainNode *p = NULL);
};

#endif