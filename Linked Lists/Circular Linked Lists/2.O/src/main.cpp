#include <iostream>
#include "singleLinkedList.h" 
#include "DoublyLinkedList.h" 
#include"CircularLinkedList.h"

int main() {
    std::shared_ptr<CLLNode> head = nullptr; 

    CLLinsertAtFront(head, 1);
    CLLinsertAtFront(head, 2);
    CLLinsertAtFront(head, 3);
    CLLinsertAtFront(head, 4);
    CLLinsertAtFront(head, 5);
    CLLinsertAtFront(head, 6);
    CLLinsertAtFront(head, 7);
    CLLinsertAtFront(head, 8);
    displayCLL(head);

    CLLinsertAtEnd(head, 0);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtFront\n";
    CLLDeleteAtFront(head);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtEnd\n";
    CLLDeleteAtEnd(head);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtPosition\n";
    CLLDeleteAtPosition(head, 3);
    displayCLL(head);




    std::cin.get();
}
