#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::pair<std::string, int> solution_(std::vector<std::vector<int>> &grid,
                                      int row, int col, int size) {
  if (size == 1) {
    return {std::to_string(grid[row][col]), grid[row][col]};
  }

  auto [top_left, a] = solution_(grid, row, col, size / 2);
  auto [top_right, b] = solution_(grid, row, col + size / 2, size / 2);
  auto [bottom_left, c] = solution_(grid, row + size / 2, col, size / 2);
  auto [bottom_right, d] =
      solution_(grid, row + size / 2, col + size / 2, size / 2);

  if (a == b && b == c && c == d && a != -1) {
    return {top_left, a};
  }

  std::string result = "(";
  result += top_left;
  result += top_right;
  result += bottom_left;
  result += bottom_right;
  result += ")";
  return {result, -1};
}

std::string solution(std::vector<std::vector<int>> &grid, int size) {
  return solution_(grid, 0, 0, size).first;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> grid(n, std::vector<int>(n));

  std::string row;
  for (int i = 0; i < n; i++) {
    std::cin >> row;

    for (int j = 0; j < n; j++) {
      grid[i][j] = row[j] - '0';
    }
  }

  std::cout << solution(grid, n) << '\n';

  return 0;
}
