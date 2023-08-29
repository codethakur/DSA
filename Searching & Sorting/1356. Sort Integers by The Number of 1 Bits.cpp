class Solution {
private:
    static int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    static bool comp(int i, int j) {
        int countI = countSetBits(i);
        int countJ = countSetBits(j);
        if (countI == countJ) {
            return i < j;
        }
        return countI < countJ;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        stable_sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
