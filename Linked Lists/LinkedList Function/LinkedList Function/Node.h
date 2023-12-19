#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    int data;
    Node* Next;

    Node(int data);
    ~Node();
};

#endif 
