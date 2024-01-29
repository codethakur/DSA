class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    int largest = i;
    int leftChild = 2 * i + 1;  // Adjusted to 0-based indexing
    int rightChild = 2 * i + 2; // Adjusted to 0-based indexing
    
    if (leftChild < n && arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }
    if (rightChild < n && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }
    
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }  
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);
        while (n > 1)
        {
            swap(arr[0], arr[n - 1]); // corrected swap indices
            n--;
            heapify(arr, n, 0);
        }
    }
};
