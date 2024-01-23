class Solution{
public:
    int table[1001][1001];

    bool isPlaindrom(string s, int i, int j)
    {
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(isPlaindrom(s, i, j))
            return 0;
        
        if(table[i][j] != -1) {
            return table[i][j];
        }

        int mn = INT_MAX;
        for(int k = i; k < j; k++){
            int tempAns = 1 + solve(s, i, k) + solve(s, k + 1, j);

            if(tempAns < mn){
                mn = tempAns;
            }
        }
        return table[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        // Initialize table with -1
        memset(table, -1, sizeof(table));
        return solve(str, 0, str.size() - 1);
    }
};
