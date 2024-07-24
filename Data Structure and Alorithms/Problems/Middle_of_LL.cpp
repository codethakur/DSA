#include<iostream>
#include<unordered_map>

struct Node{
    int data;
    Node* next;
};

void insertNodeAtBeginning(struct Node*&head, int data)
{
    Node* current = new Node();

    current->data=data;
    current->next=nullptr;
    if(head==NULL){
        head=current;
    }
    else{
        current->next=head;
        head=current;
    }
}

int length(Node*head)
{
    if(head==nullptr){
        std::cout<<"List is Empty!";
        return 0;
    }
    int NumberofNodes=0;
    Node* currNode=head;
    while (currNode!=nullptr)
    {
        NumberofNodes++;
        currNode=currNode->next;
    }
    return NumberofNodes;
    
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List!";
        return;
    }

    for (Node *curr = head; curr != nullptr; curr = curr->next)
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
    }
    std::cout << std::endl;
}

Node* middleofLLBruteForceApp(Node*head)
{
    Node* curr=head;
    int count = 0;
    while (curr!=nullptr)
    {
        count++;
        curr=curr->next;
    }
    int middIndex= count/2;
    curr=head;
    for(int i=0; i<middIndex; i++)
    {
        curr= curr->next;
    }
    return curr;
}

//Using Hash-Table
Node*middleofLLHashTableApp(Node*head)
{
    std::unordered_map<int, Node*>NodeMap;
    Node* currNode=head;
    int count=0;
    while (currNode!=nullptr)
    {
        NodeMap[count]=currNode;
        count++;
        currNode=currNode->next;
    }
    int midleIndex= count/2;
    return NodeMap[midleIndex];
    
}
//Efficent Approch

Node*middleofLLEfficientApp(struct Node* head)
{
    if(head==nullptr){
        return NULL;
    }
    Node*slow,*fast;
    slow=fast=head;
    while (fast!=nullptr &&fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return slow;
    
}
int main()
{
    Node* head=nullptr;
    insertNodeAtBeginning(head, 7);
    insertNodeAtBeginning(head,6);
    insertNodeAtBeginning(head,5);
    insertNodeAtBeginning(head, 4);
    insertNodeAtBeginning(head,3);
    insertNodeAtBeginning(head,2);
    insertNodeAtBeginning(head,1);

    Print(head);
    int NumberofNodes=length(head);
    std::cout<<"Number of Nodes: "<<NumberofNodes<<std::endl;

     Node* middle = middleofLLEfficientApp(head);
    if (middle != nullptr) {
        std::cout << "The middle node value is: " << middle->data << std::endl;
    } else {
        std::cout << "The linked list is empty." << std::endl;
    }
    return 0;

}