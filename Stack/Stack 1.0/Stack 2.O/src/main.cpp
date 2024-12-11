#include "StackLL.h"
#include <iostream>

int main() 
{
    struct StackLL* Stk = CreateStackLL();
    for (int i = 0; i < 10; i++) {
        pushintoStackLL(Stk, i);
    }
    std::cout << "Top Element: " << peekStackLL(Stk)<<std::endl;
    std::cout << "Total Stack Size: " << SizeStackLL(Stk) << std::endl;

    int Size = SizeStackLL(Stk);

    while (Size)
    {
        std::cout<< "Pop element: " << popStackLL(Stk) << std::endl;
        Size--;
    }
    if (isEmptStackLL(Stk)) {
        std::cout << "stack List is not empty" << std::endl;
    }
    else
    {
        std::cout << "stack List is  empty" << std::endl;
    }
    deleteStackLL(Stk);

    std::cout << "\n---------------\n";
    if (isEmptStackLL(Stk)) {
        std::cout << "stack List is not empty" << std::endl;
    }
    else
    {
        std::cout << "stack List is  empty" << std::endl;
    }

    return 0;
}
