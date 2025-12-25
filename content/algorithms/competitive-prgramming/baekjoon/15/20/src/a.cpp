#include <iostream>
#include <vector>

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(std::vector<std::vector<int>> &grid,
        std::vector<std::vector<int>> &count, int r, int c) {
  if (r == grid.size() - 1 && c == grid[0].size() - 1) {
    return count[r][c] = 1;
  }

  count[r][c] = 0;

  for (auto &[dr, dc] : d) {
    int next_r = r + dr, next_c = c + dc;
    if (next_r < 0 || next_r >= grid.size() || next_c < 0 ||
        next_c >= grid[0].size() || grid[next_r][next_c] >= grid[r][c]) {
      continue;
    }

    count[r][c] +=
        (count[next_r][next_c] != -1 ? count[next_r][next_c]
                                     : dfs(grid, count, next_r, next_c));
  }

  return count[r][c];
}

int solution(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<int>> count(grid.size(),
                                      std::vector<int>(grid[0].size(), -1));
  return dfs(grid, count, 0, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> grid(n, std::vector<int>(m));
  for (auto &row : grid) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
