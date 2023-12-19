// LinkedListFunctions.h
#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H

#include "Node.h"

void printList(Node* head);
void insertAtHead(Node*& head, int data);
void insertAtTail(Node*& tail, int data);
void insertAtPosition(Node*& tail, Node*& head, int data, int pos);
void deleteNode(Node*& tail, Node*& head, int position);

#endif // LINKEDLISTFUNCTIONS_H
