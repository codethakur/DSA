#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != nullptr) {
            delete next;
            next = nullptr;
        }
        cout << "memory is free now with that data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int data)
{
    if (tail == nullptr) {
        Node* initNode = new Node(data);
        tail = initNode;
        initNode->next = initNode;
        initNode->prev = initNode;
    }
    else {
        Node* currNode = tail;

        while (currNode->data != element)
        {
            currNode = currNode->next;
        }

        Node* temp = new Node(data);
        temp->next = currNode->next;
        temp->prev = currNode;
        currNode->next->prev = temp;
        currNode->next = temp;
    }
}

void deleteNode(Node*& tail, int value) {
    if (tail == nullptr)
    {
        cout << "Invalid Node" << endl;
    }
    else
    {
        Node* currNode = tail->next;

        while (currNode->data != value && currNode != tail)
        {
            currNode = currNode->next;
        }

        if (currNode->data == value) {
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;

            if (currNode == tail) {
                tail = currNode->prev;
            }

            currNode->next = nullptr;
            currNode->prev = nullptr;
            delete currNode;
        }
        else {
            cout << "Node not found with value " << value << endl;
        }
    }
}

void printList(Node* tail)
{
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail->next; // Start from the first node
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Continue until you reach the first node again
    cout << endl;
}

int main()
{
    Node* tail = nullptr;

    insertNode(tail, 0, 3);
    printList(tail);

    insertNode(tail, 3, 4);
    printList(tail);

    insertNode(tail, 4, 6);
    printList(tail);

    insertNode(tail, 6, 5);
    printList(tail);

    deleteNode(tail, 6);
    printList(tail);

    system("pause>0");
}
