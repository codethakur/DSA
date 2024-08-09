#include <iostream>
#include <limits.h>

#define Print std::cout<<
#define nL <<std::endl

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* S = new Stack();
    if (!S) {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = new int[S->capacity];
    return S;
}

int isEmpty(struct Stack *S)
{
    return(S->top==-1);
}

int size(struct Stack *S)
{
    return (S->top+1);
}
int isFull(struct Stack *S)
{
    return(S->top==S->capacity-1);
}
// void Push(struct Stack *S, int data)
// {
//     if(isFull(S))
//         std::cout<<"Stack is Full! ";
//     else
//         S->array[++S->top]=data;
// }
void doubleStack(struct Stack *S) {
    S->capacity *= 2; 
    S->array = new int[S->capacity];  //
}

void Push(struct Stack *S, int data)
{
    if(isFull(S))
       doubleStack(S);
    S->array[++S->top]=data;
}

int pop(struct Stack *S )
{
    if(isEmpty(S)){
        std::cout<<"stack is Empty";
        return INT_MIN;
    }
    else
        return (S->array[S->top--]);    
}

int peek(struct Stack *S)
{
    if(isEmpty(S)){
        std::cout<<"Stack is Empty";
        return INT_MIN;
    }else
        return (S->array[S->top]);
}

void deleteStack(struct Stack *S)
{
    if (S) {
        if (S->array) {
            delete[] S->array; 
        }
        delete S; 
    }
}


int main()
{
    int i=0;
    int capacity=5;
    struct Stack *St = createStack(capacity);
    for(i=0; i<2*capacity; i++){
        Push(St,i);
    }
    Print "stack Size:"<<size(St) nL;
    Print "Stack Peek Element is: "<<peek(St) nL;
    

    return 0;    

}
