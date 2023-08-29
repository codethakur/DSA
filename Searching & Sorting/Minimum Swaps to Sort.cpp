class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    std::vector<int> altnums(nums);
    // Create a mapping of values to their indices in the input array
    std::unordered_map<int, int> mp;
    // Sort the copy of the array to get the correct order
    sort(altnums.begin(), altnums.end());
    // Initialize a counter to keep track of the swaps
    int count = 0;
    
    // Populate the mapping with the indices of values in the original array
    for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]] = i;
    }
    
    // Iterate through the original array from the end
    for (int i = nums.size() - 1; i >= 0; --i) {
        // If the current element is not in its correct position
        if (nums[i] != altnums[i]) {
            // Find the index of the correct value in the mapping
            int index = mp[altnums[i]];
            // Update the mapping with the new index of the current value
            mp[nums[i]] = index;
            // Swap the current element with the correct element
            std::swap(nums[i], nums[index]);
            // Increment the swap counter
            count++;
        }
    }
    
    // Return the total number of swaps
    return count;
	}
};
