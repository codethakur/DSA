class Solution {
public:
    int MAX_WIDTH;
    
    string CreatedLine(int i, int j, int perwordSpace, int extraSpace, vector<string>& words) {
        string Line;
        for(int k = i; k < j; k++) {
            Line += words[k];
            if (k == j - 1) continue;
            
            // Distribute spaces evenly
            for(int z = 0; z < perwordSpace; z++) {
                Line += ' ';
                
                // Add extra space if available
                if (extraSpace > 0) {
                    Line += ' ';
                    extraSpace--;
                }
            }
        }
        
        // Pad the line with spaces up to MAX_WIDTH
        while (Line.length() < MAX_WIDTH) {
            Line += ' ';
        }
        
        return Line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAX_WIDTH = maxWidth;
        int n = words.size();
        int i = 0;
        vector<string> result;
        
        while (i < n) {
            int j = i + 1;
            int countword = words[i].length();
            int space = 0;
            
            // Find words that fit in the current line
            while (j < n && words[j].length() + countword + space < maxWidth) {
                countword += words[j].length();
                space++;
                j++;
            }
            
            int remainSpace = maxWidth - countword;
            int perwordSpace = space == 0 ? 0 : remainSpace / space;
            int extraSpace = space == 0 ? 0 : remainSpace % space;

            // If it's the last line or only one word in the line, left-justify
            if (j == n) {
                perwordSpace = 1;
                extraSpace = 0;
            }
            
            result.push_back(CreatedLine(i, j, perwordSpace, extraSpace, words));
            i = j;
        }
        
        return result;
    }
};
