class Solution {
public:
int findSmallest(vector<int> &arr, int n)
{
    // Declaring a hashmap.
    unordered_map<int, bool> hashMap;
    for (int i = 0; i < n; i++)
    {
        // Storing the values of positive integers in the map.
        if (arr[i] > 0)
            hashMap[arr[i]] = true;
    }

    // Traversing the elements from 1 to n.
    for (int i = 1; i <= n; i++)
    {
        // If the element is not found in the map, return it.
        if (hashMap[i] == false)
        {
            return i;
        }
    }
    // If all elements from 1-n are present in the map, n+1 is the required answer.
    return n + 1;
}
    int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    return findSmallest(nums, n);
}

};
