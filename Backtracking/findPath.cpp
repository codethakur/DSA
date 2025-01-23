#include <iostream>
#include <vector>
#include <string>

// Struct for direction choices
struct Choices {
    char direction;
    int dx, dy;
};

// Check if the destination is reached
constexpr bool isSolved(int x, int y, int n) {
    return (x == n - 1 && y == n - 1);
}

// Validate the move
constexpr bool isValid(int x, int y, int n, const std::vector<std::vector<int>> &mat) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1);
}

// Recursive function to find all paths
void solve(int x, int y, const int n, std::vector<std::string> &res, std::string &path, std::vector<std::vector<int>> &mat, const std::vector<Choices> &choices) {
    if (isSolved(x, y, n)) {
        res.emplace_back(path);  // More efficient than push_back
        return;
    }

    // Mark the cell as visited
    mat[x][y] = 0;

    for (const auto& [direction, dx, dy] : choices) {  // Structured binding
        int newx = x + dx;
        int newy = y + dy;

        if (isValid(newx, newy, n, mat)) {
            path.push_back(direction);
            solve(newx, newy, n, res, path, mat, choices);
            path.pop_back();  // Backtrack
        }
    }

    // Unmark the cell for other paths
    mat[x][y] = 1;
}

// Function to find all possible paths
std::vector<std::string> findPath(std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    std::vector<std::string> res;
    std::string path;

    // Inline initialization of choices
    const std::vector<Choices> choices = {
        {'U', -1, 0},
        {'D', 1, 0},
        {'L', 0, -1},
        {'R', 0, 1}
    };

    if (mat[0][0] == 1) {
        solve(0, 0, n, res, path, mat, choices);
    }

    return res;
}

// Main function
int main() {
    std::vector<std::vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    auto paths = findPath(arr);

    if (paths.empty()) {
        std::cout << "No path found.\n";
    } else {
        std::cout << "Possible paths:\n";
        for (const auto& path : paths) {
            std::cout << path << "\n";
        }
    }

    return 0;
}
