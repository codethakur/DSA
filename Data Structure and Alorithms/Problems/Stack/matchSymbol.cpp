#include <iostream>
#include <limits.h>
#include <cstring>

#define Print std::cout <<
#define nL << std::endl

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S = new Stack();
    if (!S)
    {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = new int[S->capacity];
    return S;
}

int isEmpty(struct Stack *S)
{
    return (S->top == -1);
}

int size(struct Stack *S)
{
    return (S->top + 1);
}

int isFull(struct Stack *S)
{
    return (S->top == S->capacity - 1);
}

void doubleStack(struct Stack *S) {
    S->capacity *= 2; 
    S->array = new int[S->capacity];  
}

void Push(struct Stack *S, int data)
{
    if (isFull(S))
        doubleStack(S);
    S->array[++S->top] = data;
}

int pop(struct Stack *S)
{
    if (isEmpty(S))
    {
        std::cout << "Stack is Empty";
        return INT_MIN;
    }
    else
        return (S->array[S->top--]);
}

int peek(struct Stack *S)
{
    if (isEmpty(S))
    {
        std::cout << "Stack is Empty";
        return INT_MIN;
    }
    else
        return (S->array[S->top]);
}

void deleteStack(struct Stack *S)
{
    if (S)
    {
        if (S->array)
        {
            delete[] S->array;
        }
        delete S;
    }
}

int matchSymbol(char a, char b)
{
    if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int checkExpression(const char expression[])
{
    int count = 0;
    char temp;

    struct Stack *st = createStack(5);
    for (count = 0; count < strlen(expression); count++)
    {
        if (expression[count] == '(' || expression[count] == '{' || expression[count] == '[')
        {
            Push(st, expression[count]);
        }
        if (expression[count] == ')' || expression[count] == '}' || expression[count] == ']')
        {

            if (isEmpty(st))
            {
                Print "The right symbols are more than left symbols" nL;
                deleteStack(st); // Clean up the stack
                return 0;
            }
            else
            {
                temp = pop(st);
                if (!matchSymbol(temp, expression[count]))
                {
                    std::cout << "Mismatched Symbols: " << temp << " and " << expression[count] << "\n";
                    deleteStack(st); // Clean up the stack
                    return 0;
                }
            }
        }
    }
    if (isEmpty(st))
    {
        Print "The expression is balanced" nL;
        deleteStack(st); // Clean up the stack
        return 1;
    }
    else
    {
        Print "The expression has unbalanced parentheses" nL;
        deleteStack(st); // Clean up the stack
        return 0;
    }
}

int main()
{
    int validity;
    validity = checkExpression("[a+(b*{d+2})]");
    if (validity == 1)
    {
        Print "The expression is valid" nL;
    }
    else
    {
        Print "The expression is invalid" nL;
    }
    return 0;
}
