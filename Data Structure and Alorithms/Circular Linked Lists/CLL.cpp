#include <iostream>

typedef struct CLLNode
{
    int data;
    struct CLLNode *next;
} CLLNode;

void insertAtBeginning(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = new CLLNode();

    if (!newNode)
    {
        std::cout << "Memory Error";
        return;
    }
    newNode->data = data;
    newNode->next = newNode;

    if (current == NULL)
    {
        *head = newNode;
        return;
    }
    while (current->next != *head)
        current = current->next;
    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}
void insertAtEnd(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = new CLLNode();

    if (!newNode)
    {
        std::cout << "Memory Error";
        return;
    }
    newNode->data = data;
    while (current->next != *head)
        current = current->next;
    newNode->next = newNode;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        current->next = newNode;
    }
}

void deleteLastNode(struct CLLNode **head){
    struct CLLNode *temp, *current = *head;
    if(*head==NULL){
        std::cout<<"List Empty:";
        return;
    }
    
    while(current->next!=*head){
        temp=current;
        current=current->next;
    }
    temp->next=current->next;
    delete(current);
    return;    
    
}

void deleteFrontNode(struct CLLNode**head)
{
    struct CLLNode*current = *head;
    if(head==NULL){
        std::cout<<"List is Empty";
        return;
    }
    while (current->next!=*head)
        current=current->next;
    current->next=(*head)->next;
    *head = (*head)->next;    
    return;

    
    
}
// Countion Nodes in a Cicular Linked List

int length(struct CLLNode *head)
{
    struct CLLNode *current = head;
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        current = current->next;
        count++;
    } while (current != head);
    return count;
}

// Printint the Content of Circular Linked List
void Print(struct CLLNode *head)
{
    struct CLLNode *current = head;
    if (head == NULL)
    {
        std::cout << "List Empty!";
        return;
    }
    do
    {
        std::cout << current->data;
        if (current->next != head)
        {
            std::cout << "-->";
        }
        current = current->next;

    } while (current != head);
    std::cout << std::endl;
}

int main()
{
    std::cout << "Circular Linked List " << std::endl;
    struct CLLNode *head = nullptr;

    std::cout<<"Insert the node at the Front of Circular Linked List: "<<std::endl;

    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 4);
    Print(head);
    std::cout << "Total length of Circular Linked List: " << length(head) << std::endl;

    std::cout<<"Insert the node at the End of Circular Linked List: "<<std::endl;
    insertAtEnd(&head, 40);
    Print(head);
    std::cout << "Total length of Circular Linked List: " << length(head) << std::endl;

    
    std::cout<<"Deleting Last Node in Circular Linked List"<<std::endl;
    deleteLastNode(&head);
    Print(head);
    std::cout << "Total length of Circular Linked List: " << length(head) << std::endl;

    std::cout<<"Deleting Front Node in Circular Linked List"<<std::endl;
    deleteFrontNode(&head);
    Print(head);
    std::cout << "Total length of Circular Linked List: " << length(head) << std::endl;

    return 0;
}