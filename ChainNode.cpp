#include "ChainNode.h"

ChainNode::ChainNode(float e, ChainNode *p)
{
    element = e;
    next = p;
}