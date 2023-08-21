class Solution {
public:
    string addSpaces(vector<string>& words, int maxWidth, int start, int end, int space) {
    string ans = words[start];
    
    if (start + 1 == end) {
        ans += string(maxWidth - words[start].size(), ' ');
        return ans;
    }

    int totalSpace = space + (end - start - 1); // Adjusted space calculation
    int baseSpace = totalSpace / (end - start - 1);
    int extraSpace = totalSpace % (end - start - 1);
    
    for (int i = start + 1; i < end; i++) {
        int addToSpace = baseSpace + (extraSpace-- > 0 ? 1 : 0);
        ans += string(addToSpace, ' ') + words[i];
    }
    
    return ans;
}

    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int n = words.size();
    int start = 0;
    int end = 0;

    while (start < n) {
        int lineLength = words[start].size();
        end = start + 1;
        
        while (end < n && lineLength + 1 + words[end].size() <= maxWidth) {
            lineLength += 1 + words[end].size();
            end++;
        }

        if (end == n || end - start == 1) {
            string Line = words[start];
            for (int i = start + 1; i < end; i++)
                Line += ' ' + words[i];
            Line += string(maxWidth - lineLength, ' '); // Adjust line to maxWidth
            ans.push_back(Line);
        } else {
            int space = maxWidth - lineLength;
            ans.push_back(addSpaces(words, maxWidth, start, end, space)); // Pass maxWidth instead of lineLength
        }
        start = end;
    }

    return ans;
}

};
