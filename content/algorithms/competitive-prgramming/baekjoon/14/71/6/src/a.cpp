#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<int>> &grid) {
  int num_components = 0;

  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  std::queue<std::pair<int, int>> queue;
  int d[8][2] = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
  };

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (visited[i][j] || grid[i][j] == 0) {
        continue;
      }

      num_components++;
      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (auto &[dr, dc] : d) {
          int next_r = r + dr, next_c = c + dc;

          if (next_r < 0 || next_r >= grid.size() || next_c < 0 ||
              next_c >= grid[0].size() || visited[next_r][next_c] ||
              grid[next_r][next_c] == 0) {
            continue;
          }

          visited[next_r][next_c] = true;
          queue.push({next_r, next_c});
        }
      }
    }
  }

  return num_components;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
  for (auto &row : grid) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
