class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr, arr + n); // Sort the array in ascending order
        long long count = 0;
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                if (arr[i] + arr[left] + arr[right] < sum) {
                    // If the sum of current triplet is less than sum,
                    // then all triplets with arr[left] will also satisfy the condition
                    // So, increment count by (right - left) and move left pointer to the right
                    count += (right - left);
                    ++left;
                } else {
                    // If the sum of current triplet is greater than or equal to sum,
                    // move the right pointer to the left
                    --right;
                }
            }
        }
        
        return count;
	}
		 

};
