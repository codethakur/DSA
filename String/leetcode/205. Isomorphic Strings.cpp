class Solution {
public:
   bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char, char> StoMappping;
        unordered_map<char,char>TtoMapping;
        
        for(int i=0; i<s.size(); i++)
        {
            char Schar=s[i];
            char Tchar=t[i];
            if(StoMappping.find(Schar) ==StoMappping.end())
            {
                StoMappping[Schar]=Tchar;
            }else{
                if(StoMappping[Schar]!=Tchar){
                    return false;
                }
            }if(TtoMapping.find(Tchar)==TtoMapping.end())
            {
                TtoMapping[Tchar]=Schar;
            }else{
                if(TtoMapping[Tchar]!=Schar){
                    return false;
                }
            }

        }
        return true;
    }  
};
