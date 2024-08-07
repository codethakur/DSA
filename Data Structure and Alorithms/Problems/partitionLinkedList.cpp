#include <iostream>
#include <unordered_set>

struct ListNode
{
    int data;
    ListNode *next;
};

void insertAtEnd(ListNode **head, int data)
{
    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    ListNode *current = *head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void PrintList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data;
        if (temp->next != nullptr)
        {
            std::cout << "->";
        }
        temp = temp->next;
    }
    std::cout << "->NULL" << std::endl;
}

ListNode *Partition(ListNode *head, int X)
{
    ListNode *lesser = nullptr;
    ListNode *lessderHead = nullptr;
    ListNode *greater = nullptr;
    ListNode *greaterHead = nullptr;

    if (head->data == X)
    {
        return nullptr;
    }

    while (head != nullptr)
    {
        ListNode *newNode = head->next;
        if (head->data < X)
        {
            if (lesser == nullptr)
            {
                lesser = head;
                lessderHead = lesser;
            }
            else
            {
                lesser->next = head;
                lesser = head;
            }
        }
        else
        {
            if (greater == nullptr)
            {
                greater = head;
                greaterHead = greater;
            }
            else
            {
                greater->next = head;
                greater = head;
            }
        }
        head = newNode;
    }
    if (lesser != nullptr)
    {
        lesser->next = greaterHead;
    }
    if (greater != nullptr)
        greater->next = nullptr;

    return lessderHead;
}void removeDuplicatesSortedLL(ListNode **head)
{
    ListNode *currnt = *head;

    while (currnt != nullptr && currnt->next != nullptr)
    {
        if (currnt->data == currnt->next->data)
        {
            ListNode *newNode = currnt->next->next;
            delete currnt->next;
            currnt->next = newNode;
        }
        else
        {
            currnt = currnt->next;
        }
    }
}

void removeDuplicatesUnsortedLL(ListNode **head)
{
    if (*head == nullptr)
    {
        return;
    }

    std::unordered_set<int> seen;
    ListNode *current = *head;
    ListNode *prev = nullptr;

    while (current != nullptr)
    {
        if (seen.find(current->data) != seen.end())
        {
            // Duplicate found, remove it
            prev->next = current->next;
            delete current;
        }
        else
        {
            // Not a duplicate, add to the set
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}


int main()
{
    ListNode *head = nullptr;
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    removeDuplicatesSortedLL(&head);
    PrintList(head);

    return 0;
}