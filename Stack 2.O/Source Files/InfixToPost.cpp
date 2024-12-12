#include <iostream>
#include "stack.h"


static int priotity(const char X)
{
    if (X == '(')
        return 0;
    if (X == '+' || X == '-')
        return 1;
    if (X == '*' || X == '/')
        return 2;

    return -1; // Handle invalid operators (optional)
}
static void infixToPostfix(const char expression[])
{
    int capacity = 5;
    auto S = createStack<char>(capacity);
    const char* e;  // Use const char* for safety
    char X;
    e = expression;

    while (*e != '\0')
    {
        if (isalnum(*e)) {
            std::cout << *e;
        }
        else if (*e == '(') {
            push(S, *e);
        }
        else if (*e == ')') {
            while (!isEmpty(S) && (X = pop(S)) != '(') {  // Ensure stack is not empty
                std::cout << X;
            }
        }
        else {
            while (!isEmpty(S) && priotity(peek(S)) >= priotity(*e)) {  // Check isEmpty before peek
                std::cout << pop(S);
            }
            push(S, *e);
        }
        e++;
    }

    while (!isEmpty(S)) {
        std::cout << pop(S);
    }
    std::cout << std::endl;
}


int main() {
    
    infixToPostfix("a+(b*(d+2))");

    system("pause");
    return 0;
}
