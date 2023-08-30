class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        vector<int> subarray(arr + l, arr + r + 1);
        // Sort the subarray to find the kth smallest element
        sort(subarray.begin(), subarray.end());
    
        // Return the kth smallest element
        return subarray[k - 1];
    }
};
