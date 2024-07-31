#include <iostream>
#include <unordered_map>

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int d) : data(d), next(nullptr), random(nullptr) {}
};

class HashTable
{
public:
    std::unordered_map<Node *, Node *> map;

public:
    void insert(Node *original, Node *copy)
    {
        map[original] = copy;
    }
};

Node *clone(Node *head)
{
    if (!head)
        return nullptr;

    HashTable HT;
    Node *temp = head;

    // First pass: create a copy of each node and insert it into the hash table
    while (temp != nullptr)
    {
        Node *copyNode = new Node(temp->data);
        HT.insert(temp, copyNode);
        temp = temp->next;
    }

    // Second pass: assign next and random pointers for the copied nodes
    temp = head;
    while (temp != nullptr)
    {
        Node *copyTemp = HT.map[temp];
        copyTemp->next = HT.map[temp->next];
        copyTemp->random = HT.map[temp->random];
        temp = temp->next;
    }

    return HT.map[head];
}

Node *cloneOptimal(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        Node *copyNode = new Node(temp->data);
        temp = temp->next;
    }
    temp = head;
    // connect the random Pointer
    while (temp != nullptr)
    {
        if (temp->random)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next;
    }
    // seprate the original and Copy Linked List
    temp = head;
    Node *copyHead = head->next;
    Node *copyTemp = copyHead;
    while (temp != nullptr)
    {
        temp->next = temp->next->next;
        if (copyTemp->next)
        {
            copyTemp->next = copyTemp->next->next;
        }
        temp = temp->next;
        copyTemp = copyTemp->next;
    }

    return copyHead;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << "Data: " << temp->data;
        if (temp->random)
            std::cout << ", Random Data: " << temp->random->data;
        std::cout << std::endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up random references
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    std::cout << "Original list:\n";
    printList(head);

    Node *cloneOptimal = clone(head);

    std::cout << "\nCloned list:\n";
    printList(cloneOptimal);

    // Free allocated memory (for demonstration purposes; in real usage, consider using smart pointers)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    while (cloneOptimal != nullptr)
    {
        Node *temp = cloneOptimal;
        cloneOptimal = cloneOptimal->next;
        delete temp;
    }

    return 0;
}
