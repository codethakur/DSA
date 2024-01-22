class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=s.length(), n=p.length();
        bool t[m+1][n+1];
        
        t[0][0] = true;
        
        //fill first column
        for(int i=1;i<m+1;i++)t[i][0]= false;
        
        //first row true only till p has *'s at start, cuz then it wont match with s
        bool flag = true;
        for(int j=1;j<n+1;j++){ 
            if(p[j-1] != '*') flag = false;
            t[0][j] = flag;
        }

        //fill the table
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    t[i][j] = t[i-1][j-1];
                }else if(p[j-1] == '*'){
                    t[i][j] = t[i-1][j] || t[i][j-1];
                }else{
                    t[i][j] = false;
                }
            }
        }

        return t[m][n];
    }
};
