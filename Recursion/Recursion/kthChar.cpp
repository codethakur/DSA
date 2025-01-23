class Solution {
public:
    char kthCharacter(int k) {
       std::string word = "a";
        
        while (word.size() < k) { // Stop when `word` is large enough
            std::string next = word;
            
            // Increment characters for type 1 operation
            for (char& ch : next) {
                ch = (ch == 'z') ? 'a' : ch + 1;
            }
            
            word += next; // Append the transformed string
        }

        return word[k - 1]; // Return the k-th character (0-based index)
    }
};