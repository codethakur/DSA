#include "Node.h"

Node::Node(int data) {
    this->data = data;
    this->Next = nullptr;
}

Node::~Node() {
    int value = this->data;
    delete Next;
    this->Next = nullptr;
    std::cout << "Node with data " << value << " has been deleted" << std::endl;
}
