#include "LinkedListFunctions.h"
#include <iostream>
using namespace std;

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->Next != nullptr) {
            std::cout << "->";
        }
        else {
            std::cout << "->NULL";
        }
        temp = temp->Next;
    }
    std::cout << std::endl;
}

void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->Next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->Next = temp;
    tail = temp;
}

void insertAtPosition(Node*& tail, Node*& head, int data, int pos) {
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp != nullptr) {
        temp = temp->Next;
        cnt++;
    }

    if (temp == nullptr) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    Node* nodeAtPos = new Node(data);
    nodeAtPos->Next = temp->Next;
    temp->Next = nodeAtPos;

    // If the inserted node is the last node, update the tail
    if (nodeAtPos->Next == nullptr) {
        tail = nodeAtPos;
    }
}

void deleteNode(Node*& tail, Node*& head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = temp->Next;
        temp->Next = nullptr;
        delete temp;

        // Check if the deleted node was also the tail
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        int cnt = 1;
        Node* currPosNode = head;
        Node* prev = nullptr;

        while (cnt < position && currPosNode != nullptr) {
            prev = currPosNode;
            currPosNode = currPosNode->Next;
            cnt++;
        }

        if (currPosNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        // Check if the deleted node is the last node
        if (currPosNode == tail) {
            tail = prev;
        }

        prev->Next = currPosNode->Next;
        currPosNode->Next = nullptr;
        delete currPosNode;
    }
}


