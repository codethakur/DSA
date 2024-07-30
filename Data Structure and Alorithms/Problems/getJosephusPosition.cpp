#include <iostream>

struct Node {
    int data;
    Node *next;
};
void printList(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

struct Node* getJosephusPosition()
{
    int N=0, M=0;
    std::cout<<"Enter the (N) Number of People:"<<std::endl;
    std::cin>>N;
    std::cout<<"Enter the M (Every Player get elemented):"<<std::endl;
    std::cin>>M;

    struct Node*p,*q;
    p=q=new Node();
    p->data=1;
    for(int i=0; i<=N; i++)
    {
        p->next = new Node();
        p=p->next;
        p->data=i;
    }
    p->next=q;
    //Elemenate evey M-th Node

    for(int count=N; count>1; --count)
        for(int i=0; i<M-1; i++)
            p=p->next;
        p->next=p->next->next;
    std::cout<<"Last Player left standing (Josephus Positon) is: "<<p->data<<std::endl;        
}


int main()
{
 getJosephusPosition();

 return 0;   
}