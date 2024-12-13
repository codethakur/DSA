#include <iostream>
#include "stack.h"

#if 0
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
#endif
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
            while (!isEmpty(S) && (X = pop(S)) != '(') { 
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

int postfixEvaluation(const char expression[]) {
    int capacity = 5;
    auto S = createStack<int>(capacity);

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            // Push the integer value of the digit onto the stack
            push(S, expression[i] - '0');
        }
        else {
            // Ensure there are at least two elements on the stack for a valid operation
            if (Size(S) < 2) {
                std::cerr << "Error: Malformed expression. Not enough operands for operation: " << expression[i] << std::endl;
                return -1; // Handle malformed expression
            }

            // Pop the top two elements from the stack
            int topElement = pop(S);
            int secondTopElement = pop(S);

            // Perform the operation
            switch (expression[i]) {
            case '+':
                push(S, secondTopElement + topElement);
                break;
            case '-':
                push(S, secondTopElement - topElement);
                break;
            case '*':
                push(S, secondTopElement * topElement);
                break;
            case '/':
                if (topElement == 0) {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return -1; // Handle division by zero
                }
                push(S, secondTopElement / topElement);
                break;
            default:
                std::cerr << "Error: Invalid operator encountered: " << expression[i] << std::endl;
                return -1; // Handle invalid operator
            }
        }
    }

    // After processing, there should be exactly one element left on the stack
    if (Size(S) != 1) {
        std::cerr << "Error: Malformed expression. Remaining stack size: " << Size(S) << std::endl;
        return -1;
    }

    // Return the final result
    return pop(S);
}

int main() {
    const char expression[] = "123*+5-";
    std::cout << "Postfix evaluation: " << postfixEvaluation(expression) << std::endl;

    system("pause");
    return 0;
}
