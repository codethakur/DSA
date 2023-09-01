class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1) return 1;  

       int last = fib(n-1);
       int slast = fib(n-2);  
       return last+slast;
    }
};
//```````````````````````````````````````
class Solution {
public:
    int fib(int n) {
        // Create a memoization table to store already computed values
        vector<int> memo(n + 1, -1);
        return fibMemo(n, memo);
    }

private:
    int fibMemo(int n, vector<int>& memo) {
        if (n <= 1)
            return n;

        if (memo[n] != -1)
            return memo[n];

        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];///time complexity to O(n)
    }
};
