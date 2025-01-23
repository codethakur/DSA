#include <iostream>
#include <vector>
#include <string_view>

// Function to insert an element into the sorted portion of the array
void insertNum(std::vector<int>& vec, int tempVar) {
    if (vec.empty() || vec.back() <= tempVar) {
        vec.push_back(tempVar);
        return;
    }
    int val = vec.back();
    vec.pop_back();
    insertNum(vec, tempVar);
    vec.push_back(val);
}

// Recursive function to sort the array
void SortArr(std::vector<int>& nums) {
    // Base case
    if (nums.size() <= 1) {
        return;
    }
    // Hypothesis
    int tempVar = nums.back();
    nums.pop_back();
    SortArr(nums);

    // Induction
    insertNum(nums, tempVar);
}

int main() {
    std::vector<int> nums = {0, 1, 5, 2, 6};

    // Sort the array
    SortArr(nums);

    // Print the array using a lambda function
    auto printVector = [](const std::vector<int>& vec, std::string_view separator = ", ") {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i != vec.size() - 1) {
                std::cout << separator;
            }
        }
        std::cout << "]";
    };

    printVector(nums);
    return 0;
}
