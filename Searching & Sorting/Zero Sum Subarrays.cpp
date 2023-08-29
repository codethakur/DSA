class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        vector<pair<int, int> > output;
        int count=0;
        for (int i = 0; i < n; i++) {
            int prefix = 0;
            for (int j = i; j < n; j++) {
                prefix += arr[j];
                if (prefix == 0)
                    count++;
            }
        }
     
        return count;
        
    }
// Time Complexity: O(N^2)
//Auxiliary Space: O(1)
};
//```````````````````````````````
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<int, int>mp;
        long long sum =0;
        long long count =0;
        mp[0]=1;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(mp.find(sum)!=mp.end()){
                count+=mp[sum];
            }
            mp[sum]++;
        }
        return count;
        
    }
    //Time Complexity: O(N)
    //Auxiliary Space: O(N)
};
