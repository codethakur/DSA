#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
private:
    int arr[20];
    int size;

public:
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insertele(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parentNode = index / 2;

            if (arr[parentNode] < arr[index]) {
                std::swap(arr[parentNode], arr[index]);
                index = parentNode;
            }
            else {
                break;
            }
        }
    }

    void deleteNode() {
        if (size == 0) {
            std::cout << "Empty Heap" << std::endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;

        while (i < size) {
            int leftchild = 2 * i;
            int rightchild = 2 * i + 1;
            int maxIndex = i;

            if (arr[leftchild] > arr[maxIndex]) {
                maxIndex = leftchild;
            }

            if (rightchild <= size && arr[rightchild] > arr[maxIndex]) {
                maxIndex = rightchild;
            }

            if (maxIndex != i) {
                std::swap(arr[i], arr[maxIndex]);
                i = maxIndex;
            }
            else {
                break;
            }
        }
    }


    void print() {
        for (int i = 1; i <= size; i++) {
            std::cout << arr[i] << " ";
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n && arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }
    if (rightChild <= n && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    while (n > 1)
    {
        swap(arr[n], arr[1]);
        n--;
        heapify(arr, n, 1);
    }
}


int main() {
    Heap h;
    h.insertele(50);
    h.insertele(55);
    h.insertele(53);
    h.insertele(54);
    h.insertele(52);

    h.print();
    cout << endl;
    
    h.deleteNode();
    h.print();
    cout << endl;

    int array[6] = { -1,54,53,55,52,50 };
    const int arr_size = 6;
    for (int i = arr_size / 2; i > 0; i--) {
        heapify(array,arr_size, i);
    }
    cout << "heapify arr: " << " ";
    for (int i = 0; i < arr_size; i++)
    {
        cout << array[i] << " ";
    }cout << endl;

    cout << "heapSort: ";
    heapSort(array, arr_size);

    for (int i = 1; i <= arr_size; i++) {
        cout << array[i] << " ";
    }

    system("pause>0");
}
