#include <iostream>
struct DLLNode
{
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};

void insertAtBeginning(struct DLLNode **head, int data)
{
    struct DLLNode *currnet = *head;
    struct DLLNode *newNode = new DLLNode;

    if (!newNode)
    {
        return;
    }
    newNode->prev = nullptr;
    newNode->data = data;
    newNode->next = nullptr;

    if (currnet == nullptr)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Inserting at the Ending
void insertAtEnd(struct DLLNode **head, int data)
{
    struct DLLNode *currnet = *head;
    struct DLLNode *newNode = new DLLNode();

    if (!newNode)
    {
        std::cout << "Memory Full! ";
        return;
    }
    newNode->prev = nullptr;
    newNode->data = data;
    newNode->next = nullptr;

    if (currnet == nullptr)
    {
        *head = newNode;
        return;
    }
    while (currnet->next != nullptr)
        currnet = currnet->next;
    newNode->prev = currnet;
    currnet->next = newNode;
}

// insert at the given Position

void insertAtPosition(struct DLLNode **head, int data, int position)
{
    int k = 1;
    struct DLLNode *currnet = *head;
    struct DLLNode *newNode = new DLLNode();

    if (!newNode)
    {
        std::cout << "Memory Full!";
        return;
    }
    newNode->prev = nullptr;
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 1)
    {
        newNode->next = *head;
        newNode->prev = nullptr;
        if (*head)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    while (k < position - 1 && currnet->next != nullptr)
    {
        currnet = currnet->next;
        k++;
    }
    if (k < position - 1)
    {
        std::cout << "The Desired Position does not exits! ";
        return;
    }
    newNode->next = currnet->next;
    newNode->prev = currnet;
    if (currnet->next)
        currnet->next->prev = newNode;
    currnet->next = newNode;
    return;
}
//                  Deleting

// Deleting the  First Node

void DeleteFrontNode(struct DLLNode **head)
{
    struct DLLNode *temp = *head;
    if (*head == NULL)
    {
        std::cout << "List is empty!";
        return;
    }
    temp = *head;
    *head = (*head)->next;
    (*head)->prev = nullptr;
    delete temp;
}

void DeleteLastNode(struct DLLNode **head)
{
    struct DLLNode *temp, *current = *head;
    if (*head == NULL)
    {
        std::cout << "List is empty!";
        return;
    }
    while (current->next != nullptr)
    {
        current = current->next;
    }

    temp = current->prev;
    temp->next = current->next;
    delete current;
    return;
}

void deletAtPosition(struct DLLNode **head, int position)
{
    struct DLLNode *temp, *current = *head;

    int k = 1;
    if (*head == NULL)
    {
        std::cout << "Invqalid Position.";
        return;
    }
    if (position = 1)
    {
        (*head) = (*head)->next;
        if (*head != nullptr)
            (*head)->prev = nullptr;
        delete temp;
        return;
    }

    while (k < position && temp->next != nullptr)
    {
        temp = temp->next;
        k++;
    }
    if (k < position - 1)
    {
        std::cout << "Desired position Does not exits!";
        return;
    }
    current = temp->prev;
    current->next = temp->next;

    if (temp->next)
        temp->next->prev = current;
    delete temp;
    return;
}

void Print(struct DLLNode *head)
{
    struct DLLNode *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->data;
        if (temp->next != nullptr)
        {
            std::cout << "->";
        }
        else
        {
            std::cout << "->NULL";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Insert at Beginning in Double Linked List: " << std::endl;

    struct DLLNode *head = nullptr;
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 15);
    Print(head);

    std::cout << "Insert at End in Double Linked List: " << std::endl;

    insertAtEnd(&head, 100);
    Print(head);

    std::cout << "Insert at Given Position in Double Linked List: " << std::endl;
    insertAtPosition(&head, 22, 3);
    Print(head);

    std::cout << "Deleting  front Node in  Double Linked List: " << std::endl;
    DeleteFrontNode(&head);
    Print(head);

    std::cout << "Deleting Last in  Double Linked List: " << std::endl;
    DeleteLastNode(&head);
    Print(head);

    std::cout << "Deleting Node at givign Position  in  Double Linked List: " << std::endl;
    deletAtPosition(&head,2);
    Print(head);

    std::cin.get();
}