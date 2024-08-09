#include<iostream>
#include <limits.h>

#define Print std::cout<<
#define nL <<std::endl

struct ListNode{
    int data;
    struct ListNode *next;
};

struct Stack{
    struct ListNode *top;
};

struct Stack *createStack()
{
    struct Stack *S = new Stack();
    S->top=NULL;
    return S;
}

void Push(struct Stack *S, int data)
{
    struct ListNode *temp = new ListNode();
    if(!temp)
    {
        Print "Stack is Overflow" nL;
        return;
    }
    temp->data=data;
    temp->next = S->top;
    S->top=temp;

}
int isEmpty(struct Stack *S){
    return S->top==NULL;
}

int size(struct Stack * S)
{
    int count = 0;
    struct ListNode *temp = S->top;

    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

int Pop(struct Stack * S)
{
    int data;
    struct ListNode*temp;
    if(isEmpty(S))
       return INT_MIN;
    temp=S->top;
    S->top= S->top->next;
    data= temp->data;
    delete(temp);
    return  data;
}
int Peek(struct Stack *S)
{
    if(isEmpty(S))
        return INT_MIN;
    return S->top->data;    

}

void deletestack(struct Stack * S)
{
    struct ListNode *temp, *p;

    p=S->top;
    while (p)
    {
        temp = p->next;
        delete(temp);
    }
    delete(S);
    
}

int main()
{
    int i=0;
    struct Stack *S=createStack();
    for(i=0; i<=10; i++)
    {
        Push(S,i);
    }

    Print "Stack peek element is "<<Peek(S) nL;
    Print "stack Size is "<<size(S) nL;
    
    for(i=0; i<=10; i++){
        Print "Popped Element is: "<<Pop(S) nL;
    }

    if(isEmpty(S))
        Print "Stack is Empty!" nL;
    else
        Print "Stack is Not Empty" nL;
    deletestack(S);

    return 0;    
}