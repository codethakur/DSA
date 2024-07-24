#include <iostream>
#include <vector>

template<typename T>
class UnrolledLinkedList {
private:
    struct Node {
        std::vector<T> elements;
        Node* next;

        Node(int capacity) : elements(), next(nullptr) {
            elements.reserve(capacity);
        }
    };

    Node* head;
    Node* tail;
    int nodeCapacity;
    int size;

public:
    UnrolledLinkedList(int capacity) : head(nullptr), tail(nullptr), nodeCapacity(capacity), size(0) {}

    ~UnrolledLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const T& value) {
        if (head == nullptr) {
            head = new Node(nodeCapacity);
            tail = head;
        }

        if (tail->elements.size() == nodeCapacity) {
            tail->next = new Node(nodeCapacity);
            tail = tail->next;
        }

        tail->elements.push_back(value);
        ++size;
    }

    void remove(const T& value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            for (auto it = current->elements.begin(); it != current->elements.end(); ++it) {
                if (*it == value) {
                    current->elements.erase(it);
                    --size;

                    if (current->elements.empty()) {
                        if (prev == nullptr) {
                            head = current->next;
                        } else {
                            prev->next = current->next;
                        }

                        if (current == tail) {
                            tail = prev;
                        }

                        delete current;
                    }
                    return;
                }
            }

            prev = current;
            current = current->next;
        }
    }

    void traverse() const {
        Node* current = head;

        while (current != nullptr) {
            for (const auto& elem : current->elements) {
                std::cout << elem << " ";
            }
            current = current->next;
        }

        std::cout << std::endl;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    UnrolledLinkedList<int> list(4); // Node capacity is 4

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    std::cout << "List after insertions: ";
    list.traverse();

    list.remove(3);
    std::cout << "List after removing 3: ";
    list.traverse();

    list.remove(1);
    std::cout << "List after removing 1: ";
    list.traverse();

    std::cout << "Size of the list: " << list.getSize() << std::endl;

    return 0;
}
