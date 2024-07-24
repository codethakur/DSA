#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

struct Node
{
    int data;
    Node *next;
};

void insertNodeAtBeginning(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if (!newNode)
    {
        std::cout << "Memory Error!";
        return;
    }
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

int length(Node *head)
{
    Node *curr = head;
    int count = 0;

    if (head == nullptr)
    {
        return 0;
    }
    for (curr = head; curr != nullptr; curr = curr->next)
    {
        count++;
    }
    return count;
}

Node *kthNodeFromEnd(Node *head, int k)
{
    if (k > length(head) || k <= 0)
    {
        std::cout << "Error: K is out of range" << std::endl;
        return nullptr;
    }

    Node *ptemp = head, *kthNode = head;

    for (int i = 0; i < k - 1; i++)
    {
        ptemp = ptemp->next;
    }

    while (ptemp->next != nullptr)
    {
        ptemp = ptemp->next;
        kthNode = kthNode->next;
    }
    return kthNode;
}

Node *findLoopBeginning(Node *head)
{
    Node *outer = head;
    while (outer != nullptr)
    {
        Node *inner = outer->next;
        while (inner != nullptr)
        {
            if (inner == outer)
            {
                std::cout << "Loop begins at node with data: " << outer->data << std::endl;
                return outer;
            }
            inner = inner->next;
        }
        outer = outer->next;
    }
    std::cout << "No loop detected." << std::endl;
    return nullptr;
}

Node *findLoopBeginningUsingHashing(Node *head)
{
    Node *current = head;
    std::unordered_set<Node *> visited;

    while (current != nullptr)
    {
        if (visited.find(current) != visited.end())
        {

            return current;
        }
        visited.insert(current);
        current = current->next;
    }
    return nullptr;
}

Node *findLoopBeginningUsingSorting(Node *head)
{
    Node *current = head;
    std::vector<Node *> nodeArray;

    while (current != nullptr)
    {
        nodeArray.push_back(current);
        current = current->next;
    }

    // Sort the nodes based on their memory addresses
    std::sort(nodeArray.begin(), nodeArray.end());
    Node *temp = nullptr;
    // Look for a repeated node (which indicates a loop)
    for (temp = 0; nodeArray.size(); temp = temp->next)
    {
        if (temp == temp->next)
        {
            std::cout << "Loop begins at node with data: " << temp->data << std::endl;
            return temp;
        }
    }

    std::cout << "No loop detected." << std::endl;
    return nullptr;
}

int findLoopBeginningUsingFloyd(Node *head)
{
    if (!head)
        return 0;

    Node *slow = head;
    Node *fast = head;

    // Detecting loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            std::cout << "Loop begins at node with data: " << slow->data << std::endl;
            return 1;
        }
    }

    std::cout << "No loop in the Linked List!" << std::endl;
    return 0;
}

void SortedInsert(Node **head, int data)
{
    // Create a new node and assign the data to it
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    // Special case for the head end
    if (*head == nullptr || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Locate the node before the point of insertion
    Node *current = *head;
    while (current->next != nullptr && current->next->data < newNode->data)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

Node *reverseList(Node *head)
{
    Node *prev, *curr, *Next;
    prev = NULL;
    curr = head;

    while (curr != nullptr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

Node *reverseListRecusive(Node *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return head;
    }
    Node *secondNode = head->next;
    head->next = nullptr;
    Node *ReverseList = reverseListRecusive(secondNode);
    secondNode->next = head;
    return ReverseList;
}

Node *intersectingNodeBruteForce(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return head1;
        std::cout << "Its singly Linked List";
    }
    Node *temp;
    while (head1 != nullptr)
    {
        temp = head2;
        while (temp != nullptr)
        {
            if (temp == head1)
            {
                std::cout << "Intersecting node is: " << head1->data << std::endl;
                return head1;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return nullptr;
}

Node* intersectingNodeSortTech(Node* head1, Node* head2) {
    std::vector<Node*> SortedArray;

    Node* temp = head1;
    while (temp != nullptr) {
        SortedArray.push_back(temp);
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr) {
        SortedArray.push_back(temp);
        temp = temp->next;
    }

    std::sort(SortedArray.begin(), SortedArray.end());

    for (size_t i = 1; i < SortedArray.size(); ++i) {
        if (SortedArray[i] == SortedArray[i - 1]) {
            std::cout << "Intersecting node is: " << SortedArray[i]->data << std::endl;
            return SortedArray[i];
        }
    }

    std::cout << "No intersection found." << std::endl;
    return nullptr;
}

// Function to find the intersection node using hashing technique.
Node* intersectingNodeHashingTech(Node* head1, Node* head2) {
    std::unordered_set<Node*> visited;

    Node* current = head1;
    while (current != nullptr) {
        visited.insert(current);
        current = current->next;
    }

    current = head2;
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            std::cout << "Intersecting node is: " << current->data << std::endl;
            return current;
        }
        current = current->next;
    }

    std::cout << "No intersection found." << std::endl;
    return nullptr;
}

//Find the middle of LinkedList

Node* middleofLinkedList(Node* head)
{
    Node*curr = head;
    int numberofNode = length(head);
    int middleIndex = numberofNode/2;
    
   for(int i=0; i<middleIndex; i++)
    curr=curr->next;
   return curr;
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head = nullptr;
    
    insertNodeAtBeginning(head1, 40);
    insertNodeAtBeginning(head1, 7);
    insertNodeAtBeginning(head1, 15);
    insertNodeAtBeginning(head1, 10);

    insertNodeAtBeginning(head2, 14);
    insertNodeAtBeginning(head2, 13);
    insertNodeAtBeginning(head2, 12);
    insertNodeAtBeginning(head2, 11);

    insertNodeAtBeginning(head, 17);
    insertNodeAtBeginning(head, 16);
    insertNodeAtBeginning(head, 15);

    // head1->next->next->next->next = head;  
    // head2->next->next->next->next = head;  
    // intersectingNodeHashingTech(head1, head2);
    Node* middle = middleofLinkedList(head);
    if (middle != NULL) {
        std::cout << "The middle node value is: " << middle->data << std::endl;
    } else {
        std::cout << "The linked list is empty." << std::endl;
    }


    return 0;
}