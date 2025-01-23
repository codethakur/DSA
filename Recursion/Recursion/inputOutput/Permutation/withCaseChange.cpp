#include <iostream>
#include <string>
#include <string_view>
void Solve(std::string_view input, std::string output)
{
    if (input.empty())
    {
        std::cout << output << std::endl;
        return;
    }
    std::string op1 = output;
    std::string op2 = output;

    op1.push_back(input.front());
    op2.push_back(toupper(input.front()));

    // Remove the first character by creating a new `std::string_view` slice
    std::string_view remaining = input.substr(1);

    Solve(remaining, op1);
    Solve(remaining, op2);
    return;
}
int main()
{
    std::string input = "";
    std::cout << "Enter the string: ";
    std::cin >> input;
    std::string_view input_view(input); // Create a string_view for the input
    std::string oputput = "";

    Solve(input, oputput);
    return 0;
}