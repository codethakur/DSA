#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Next;

    Node(int data)
    {
        this->data = data;
        this->Next = nullptr;
    }
    ~Node()
    {
        int value = this->data;
        if (this->Next != nullptr) {
            delete Next;
            Next = NULL;
        }
        cout << "memory is free now with that data " << value << endl;
        
    }

};

void insertNode(Node*& tail, int element, int data)
{
    if (tail == nullptr) {
        Node* initNode = new Node(data);
        tail = initNode;
        initNode->Next = initNode;
    }
    else {
        Node* currNode = tail;

        while (currNode->data != element)
        {
            currNode = currNode->Next;
        }
        Node* temp = new Node(data);
        temp->Next = currNode->Next;
        currNode->Next = temp;
    }
}

void deleteNode(Node*& tail, int value) {
    if (tail == NULL)
    {
        cout << "Invalid Node" << endl;

    }
    else
    {
        Node* prev = tail;
        Node* currNode = prev->Next;

        while (currNode->data != value)
        {
            prev = currNode;
            currNode = currNode->Next;
        }
        prev->Next = currNode->Next;

        if (currNode == prev) {
            tail = NULL;
        }
        else if ( tail == currNode)
        {
            tail = currNode->Next;
        }

        currNode->Next = NULL;
        delete currNode;

    }
}

void printList(Node* tail)
{
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->Next;
    } while (temp != tail);
    cout << endl;
}


int main()
{
    Node* tail = nullptr;

    insertNode(tail, 0, 3);
    printList(tail);

    insertNode(tail, 3, 4);  // Insert after the element with data value 3
    printList(tail);

    insertNode(tail, 4, 6);  // Insert after the element with data value 4
    printList(tail);

    insertNode(tail, 6, 5);  // Insert after the element with data value 6
    printList(tail);

    deleteNode(tail, 6);
    printList(tail);

    system("pause>0");
}
