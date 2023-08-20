class Solution {
public:
    string intToRoman(int num) {
        map<int, string> romanNumerals = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
    string result = "";
    // Iterate through the map in reverse order
    for (auto it = romanNumerals.rbegin(); it != romanNumerals.rend(); ++it) {
        // While the input number is greater than or equal to the current map key
        while (num >= it->first) {
            // Add the corresponding Roman numeral to the result string
            result += it->second;
            // Subtract the map key from the input number
            num -= it->first;
        }
    }
    return result;
    }
};
