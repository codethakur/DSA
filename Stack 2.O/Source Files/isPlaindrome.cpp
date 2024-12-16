#include <iostream>
#include "stack.h"


int isPlaindrome(const char A[])
{
    Stack<char>* stk = createStack<char>(strlen(A));

    int  i = 0;
    while (A[i] && A[i] != 'X') {
        push(stk, A[i]);
        i++;
    }
    i++;
    while (A[i]) {
        if (isEmpty(stk) || A[i] != pop(stk)) {
            std::cout << "Not a palindrom\n";
            return 0;
        }
        i++;
    }
    std::cout << "Palaindrome\n";
    return 1;
}


int main() {
    isPlaindrome("ababaXababa");
    isPlaindrome("ababababXbababbbbabba");



    system("pause");
    return 0;
}
