class Solution{
    private:
    static bool comp(int i, int j) {
        return __builtin_popcount(i) > __builtin_popcount(j);
    }
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
       stable_sort(arr, arr + n, comp);
    }
  // O(n log n)  n number of arr long(n) sort
};
