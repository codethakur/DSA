class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
       for(int i =0; i<time.size(); i++)
       {
           for(int j=i+1; j<time.size(); j++)
           {
               if((time[i]+time[j])%60==0) count++;
           }
       } 
       return count; 
    }
};//TLE ==> O(N^2)


///////////~~~~~~~~~~~~~///////////////////
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        vector<int>Rem2count(60,0);
       for(int i =0; i<time.size(); i++)
       {
           int x = time[i];
           int rem = x%60;
           if(!rem) count+=Rem2count[0];
           else count+=Rem2count[60-rem];
           Rem2count[rem]++;
       } 
       return count;
    }
};
