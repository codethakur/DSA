class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
         unordered_map<int, int> countMap;
        int missing = 0, repeating = 0;

        // Count the occurrences of each element
        for (int num : arr) {
            countMap[num]++;
        }

        // Find the repeating and missing numbers
        for (int i = 1; i <= n; i++) {
            if (countMap.find(i) == countMap.end()) {
                missing = i;
            } else if (countMap[i] == 2) {
                repeating = i;
            }
        }

        return {repeating, missing};
    }
};
