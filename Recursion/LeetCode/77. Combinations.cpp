//Facebook 5, Google 5, Amazon 2, Microsoft 2,........ .

class Solution {
public:
    void Sov(int n, int start, vector<int>& output, int k, vector<vector<int>>& result) {
        if (output.size() == k) {
            result.push_back(output);
            return;
        }

        if (start > n)
            return;

        output.push_back(start);
        Sov(n, start + 1, output, k, result);
        output.pop_back();
        Sov(n, start + 1, output, k, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> output;
        Sov(n, 1, output, k, result);
        return result;
    }
};
