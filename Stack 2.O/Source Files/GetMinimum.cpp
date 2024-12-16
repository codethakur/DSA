#include <iostream>
#include "stack.h"



template <typename T>
void PushIntoDoublestack(Stack<T>* mainStack, Stack<T>* minStack, T data) {
    // Push into main stack
    push(mainStack, data);
    std::cout << "Pushed " << data << " into mainStack. Current top: "
        << peek(mainStack) << ", mainStack Size: " << Size(mainStack) << std::endl;

    // Update minStack with proper checks
    if (isEmpty(minStack)) {
        push(minStack, data);
        std::cout << "minStack was empty. Pushed " << data << " into minStack." << std::endl;
    }
   /*
    else {
        T currentMin = peek(minStack);
        if (data <= currentMin) {
            push(minStack, data);
            std::cout << "Pushed " << data << " into minStack as new minimum." << std::endl;
        }
        else {
            push(minStack, currentMin);
            std::cout << "Pushed current minimum " << currentMin << " into minStack." << std::endl;
        }
    }*/
     else if (peek(minStack) >= data) {
         push(minStack, data);
         std::cout << "Pushed " << data << " into minStack as new minimum." << std::endl;
     }
     else {
         push(minStack, peek(minStack));
         std::cout << "Pushed current minimum " << peek(minStack) << " into minStack." << std::endl;
     }

}


int main() {
    int capacity = 5;
    auto mainStack = createStack<int>(capacity);
    auto minStack = createStack<int>(capacity);

    for (int i = 0; i < capacity; i++) {
        PushIntoDoublestack(mainStack, minStack, (7 * i) % 4);
    }

    if (!isEmpty(mainStack)) {
        std::cout << "Top Element is: " << peek(mainStack) << std::endl;
    }
    else {
        std::cerr << "mainStack is empty! Cannot peek." << std::endl;
    }

    if (!isEmpty(minStack)) {
        std::cout << "Minimum element is: " << getMinimum(minStack) << std::endl;
    }
    else {
        std::cerr << "minStack is empty! Cannot get minimum." << std::endl;
    }

    std::cout << "Stack size is: " << Size(mainStack) << std::endl;

    system("pause");
    return 0;
}
