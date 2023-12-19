#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* Prev;
	Node* Next;

	Node(int data)
	{
		this->data = data;
		this->Prev = NULL;
		this->Next = NULL;
	}
};

void insertAtHead(Node*& head, Node*& tail, int data)
{
	Node* temp = new Node(data);
	if (head == NULL && tail == NULL) {
		head = tail = temp;
	} else {
		temp->Next = head;
		head->Prev = temp;
		head = temp;
	}
}

void insertAtTail(Node*& tail, int data)
{
	Node* temp = new Node(data);
	if (tail == NULL) {
		tail = temp;
	} else {
		tail->Next = temp;
		temp->Prev = tail;
		tail = temp;
	}
}

void insertAtPosition(Node*& tail, Node*& head, int data, int pos)
{
	if (pos == 1) {
		insertAtHead(head, tail, data);
		return;
	}

	Node* temp = head;
	int cnt = 1;
	while (cnt < pos - 1 && temp != NULL) {
		temp = temp->Next;
		cnt++;
	}

	if (temp == NULL) {
		cout << "Invalid position." << endl;
		return;
	}

	Node* nodeAtPos = new Node(data);
	nodeAtPos->Next = temp->Next;

	if (temp->Next != NULL) {
		temp->Next->Prev = nodeAtPos;
	}

	temp->Next = nodeAtPos;
	nodeAtPos->Prev = temp;

	// If the inserted node is the last node, update the tail
	if (nodeAtPos->Next == nullptr) {
		tail = nodeAtPos;
	}
}
void deleteNodeAtposition(Node* & head, int position) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> Next -> Prev = NULL;
        head = temp ->Next;
        temp -> Next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* currPosNode = head;
        Node* Prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            Prev = currPosNode;
            currPosNode = currPosNode -> Next;
            cnt++;
        }

        currPosNode -> Prev = NULL;
        Prev -> Next = currPosNode -> Next;
        currPosNode -> Next = NULL;

        delete currPosNode;

    }
}


void printList(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		std::cout << temp->data;
		if (temp->Next != NULL) {
			std::cout << "->";
		}
		else {
			std::cout << "->NULL";
		}
		temp = temp->Next;
	}
	std::cout << std::endl;
}

int getLength(Node* head)
{
	Node* temp = head;
	int Length = 0;
	while (temp != NULL)
	{
		Length++;
		temp = temp->Next;
	}
	return Length;
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;

	printList(head);

	insertAtHead(head, tail, 11);
	printList(head);

	insertAtHead(head, tail, 12);
	printList(head);

	insertAtHead(head, tail, 13);
	printList(head);

	insertAtHead(head, tail, 14);
	printList(head);

	insertAtTail(tail, 15);
	printList(head);

	insertAtPosition(tail, head, 100, 2);
	printList(head);

    deleteNodeAtposition(head, 3);
    printList(head);
	
	deleteNodeAtposition(head, 5);
    printList(head);

	cout << "Length = " << getLength(head);
	system("pause>0");
}
