class Solution {
public:
    int countSubsetSum(vector<int>& nums,int s1){
        int n=nums.size();
        int t[n+1][s1+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
            if(nums[i-1]<=j){
                t[i][j]=t[i-1][j] + t[i-1][j-nums[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
            }
        }
        return t[n][s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     int n=nums.size();
        int sumOfnums=0;
        
        for(int i=0; i<nums.size(); i++){
            sumOfnums+=nums[i];
        }
         if(((sumOfnums+target)%2!=0) || abs(target)>sumOfnums){
             return 0;
         }
    int s1=(target+sumOfnums)/2;
     return countSubsetSum(nums,abs(s1));
    }
};
