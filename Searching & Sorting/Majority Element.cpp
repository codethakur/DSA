class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
    unordered_map<int, int> mp;
    
    for (int i = 0; i < size; i++) {
        mp[a[i]]++;
    }
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > size / 2) {
            return it->first;
        }
    }
    
    return -1;
        
    }
};
