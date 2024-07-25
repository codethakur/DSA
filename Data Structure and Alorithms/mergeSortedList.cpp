#include <iostream>
struct Node
{
    int data;
    struct Node *next = nullptr;
};

struct Node *insertAtEnd(Node *&head, int data)
{
    Node *curr, *temp;
    temp = new Node();
    temp->data = data;
    temp->next = NULL;
    curr = head;
    if (curr == NULL)
    {
        head = temp;
    }
    else
    {
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

struct Node *mergeSortListIterative(struct Node *head1, struct Node *head2)
{
    struct Node *newNode = new Node();
    struct Node *temp = newNode;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;
    temp = newNode->next;
    free(newNode);
    return temp;
}
struct Node *mergeSortList(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeSortList(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeSortList(head2->next, head1);
    }
    return result;
}
struct Node *reversePairIterative(struct Node *head)
{
    Node *temp1 = nullptr;
    Node *temp2 = nullptr;   // This will be used to update the head of the list
    Node *newHead = nullptr; // This will hold the new head of the list
    Node *curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (temp1 != nullptr)
        {
            temp1->next->next = curr->next; // Fixing the connection of the previous pair
        }
        temp1 = curr->next;
        curr->next = curr->next->next;
        temp1->next = curr;

        if (temp2 == nullptr)
        {
            temp2 = temp1;   // Update temp2 only once, to point to the new head
            newHead = temp1; // Assign newHead to the first reversed pair
        }
        else
        {
            temp2->next->next = temp1; // Fixing the connection of the previous pair
            temp2 = temp1->next;       // Move temp2 to the end of the current pair
        }

        curr = curr->next;
    }

    return newHead == nullptr ? head : newHead;
}

struct Node *reversePairYT(struct Node *head)
{
    struct Node *dummy = new Node();
    dummy->next = head;
    struct Node *prev = dummy;
    struct Node *curr = head;

    struct Node *NextPair;
    struct Node *second;

    while (curr != nullptr && curr->next != nullptr)
    {
        NextPair = curr->next->next;
        second = curr->next;

        second->next = curr;
        curr->next = NextPair;
        prev->next = second;

        prev = curr;
        curr = curr->next;
    }
    return dummy->next;
}
// Function to print the list

struct Node *reversePairRecursive(struct Node* head)
{
    if(head==NULL || head->next==NULL){
        return NULL;
    }else{
        struct Node *temp;
        temp=head->next;
        head->next=temp->next;
        temp->next=head;
        head=temp;
        head->next->next=reversePairRecursive(head->next->next);

    return head;
    }
    
}

void Print(struct Node *head)
{
    struct Node *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data;
        if (curr->next != nullptr)
        {
            std::cout << "->";
        }
        else
        {
            std::cout << "->NULL";
        }
        curr = curr->next;
    }
}

int main()
{
    struct Node *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    head = reversePairRecursive(head);
    Print(head);

    return 0;
}