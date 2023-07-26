//https://leetcode.com/problems/powx-n/
//50. Pow(x, n)

class Solution {
public:
    double binaryExp(double x, long long n)
    {
        if(n==0) {
            return 1;
        }
        if(n<0) {
            return 1.0/ binaryExp(x, -n);
        }
        if(n%2==1){
            return x * binaryExp(x*x,(n-1)/2);
        }
        else{
            return binaryExp(x * x, n / 2);
        }
    }
    double myPow(double x, int n) {
        return binaryExp(x,(long)(long)n);
    }
};
