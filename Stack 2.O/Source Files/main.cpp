#include <iostream>
#include "stack.h"

int matchSymbol(char a, char b)  {
    if (a == '(' && b == ')') {
        return 1;
    }
    if (a == '[' && b == ']') {
        return 1;
    }
    if (a == '{' && b == '}') {
        return 1;
    }
    return 0;
}

int checkExpression(const char expression[])
{
    char temp;
    int capacity = 5;
    auto S = createStack<char>(capacity);
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(S, expression[i]);
        }
        if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(S)) {
                std::cerr << "The right symbols are more than the left symbols\n";
                return 0;
            }
            else
            {
                temp = pop(S);
                if (!matchSymbol(temp, expression[i])) {
                    std::cerr << "The matched symbols are: " << temp << " and " << expression[i] << std::endl;
                    return 0;
                }
            }
        }
    }
    if (isEmpty(S)) {
        std::cout << "\nThe Expression has balanced symbols\n";
        return 1;
    }
    else {
        std::cerr << "The Expression is unbalanced\n";
    }
    return 0;
}

int main() {
    int validity;
    validity = checkExpression("[a+(b*{d+2}))");
    if (validity == 1) {
        std::cout << "The expression is valid\n";
    }
    else
    {
        std::cout << "The expression is invalid\n";
    }

    system("pause");
    return 0;
}
