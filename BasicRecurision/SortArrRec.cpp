#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void insertTemp(vector<int>& nums, int temp) {
        if (nums.empty() || nums[nums.size() - 1] <= temp) {
            nums.push_back(temp);
            return;
        }

        int val = nums[nums.size() - 1];
        nums.pop_back();
        insertTemp(nums, temp);
        nums.push_back(val);
    }

    void sortRecursion(vector<int>& nums) {
        if (nums.size() == 0) return;

        int temp = nums[nums.size() - 1];
        nums.pop_back();
        sortRecursion(nums);

        insertTemp(nums, temp);                    //912. Sort an Array LeetCode TLE, Just to understand how recursion works.

    }

    vector<int> sortArray(vector<int>& nums) {
        sortRecursion(nums);
        return nums;
    }
};


int main() {
    Solution solution;
    vector<int> nums;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> sortedNums = solution.sortArray(nums);

    cout << "Sorted array: ";
    for (int num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
