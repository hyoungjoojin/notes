#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int solution(std::vector<std::vector<int>> &grid) {
  int num_rows = grid.size(), num_cols = grid[0].size();

  std::vector<std::vector<int>> memo(num_rows, std::vector<int>(num_cols)),
      memo_row(num_rows, std::vector<int>(num_cols)),
      memo_col(num_rows, std::vector<int>(num_cols));

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      memo_row[i][j] =
          (j == 0 ? grid[i][j]
                  : (grid[i][j] == 1 ? memo_row[i][j - 1] + 1 : 0));

      memo_col[i][j] =
          (i == 0 ? grid[i][j]
                  : (grid[i][j] == 1 ? memo_col[i - 1][j] + 1 : 0));

      if (i == 0 || j == 0) {
        memo[i][j] = grid[i][j];
        continue;
      }

      if (grid[i][j] == 0) {
        memo[i][j] = 0;
        continue;
      }

      memo[i][j] = std::min(memo_row[i][j - 1], memo_col[i - 1][j]);
      memo[i][j] = std::min(memo[i][j], memo[i - 1][j - 1]);
      memo[i][j] += 1;
    }
  }

  int result = 0;

  for (auto &row : memo) {
    for (int &i : row) {
      result = std::max(result, i);
    }
  }

  return result * result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> grid(n, std::vector<int>(m));

  std::string row;
  for (int i = 0; i < n; i++) {
    std::cin >> row;

    for (int j = 0; j < m; j++) {
      grid[i][j] = row[j] - '0';
    }
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
