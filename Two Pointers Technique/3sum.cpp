class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if((nums[i] + nums[j] + nums[k] == 0) ){
                        vector<int>temp = {nums[i], nums[j], nums[k]};      //TC = O(n^3logn) Time Limit Exceeded
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>output(st.begin(), st.end());
        return output;
    }
};

/////////////////////////////```````````````````````````/////////////////////////////
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            set<int>hash;
            for(int j=i+1; j<n; j++){
                int third = - (nums[i]+nums[j]);     //TC = O(n^2logn)  but SC = O(N) + longN
                if(hash.find(third)!=hash.end())
                {
                    vector<int>v={nums[i], nums[j], third};//[]
                    sort(v.begin(),v.end());
                    st.insert(v);//[  []      ]
                }
                hash.insert(nums[j]);
            }
        }
        vector<vector<int>>output(st.begin(), st.end());
        return output;
    }
};
/////////////////////////////```````````````````````````/////////////////////////////
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
         sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<n-2; i++){
            if(i==0 || (nums[i] &&nums[i-1])){
                int low =i+1, high=n-1;
                while(low<high)
                {
                    if(nums[i]+nums[low]+nums[high]<0){
                        low++;
                    }
                    else if(nums[i]+nums[low]+nums[high]>0){
                        high--;
                    }
                    else{
                        st.insert({nums[i],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        vector<vector<int>>output(st.begin(), st.end());
        return output;
    }
};
/////////////////////////////```````````````````````````/////////////////////////////
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output; 
        sort(nums.begin(), nums.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(nums.size())-2; i++) {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                int lo = i+1, hi = (int)(nums.size())-1, sum = 0 - nums[i]; 
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[lo]);                //TC = O(n^2logn)  ! SC 
                        temp.push_back(nums[hi]); 
                        output.push_back(temp);
                        
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return output;
    }
};
