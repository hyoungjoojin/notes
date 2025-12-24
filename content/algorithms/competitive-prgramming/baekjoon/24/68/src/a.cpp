#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<bool>> land(grid.size(),
                                      std::vector<bool>(grid.size(), true)),
      visited(grid.size(), std::vector<bool>(grid.size(), false));
  std::queue<std::pair<int, int>> queue;
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int result = 0;
  bool changed = true, finished = false;

  while (!finished) {
    if (changed) {
      changed = false;

      int num_components = 0;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
          if (visited[i][j] || !land[i][j]) {
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
                  next_c >= grid.size() || visited[next_r][next_c] ||
                  !land[next_r][next_c]) {
                continue;
              }

              visited[next_r][next_c] = true;
              queue.push({next_r, next_c});
            }
          }
        }
      }

      result = std::max(result, num_components);

      for (auto &row : visited) {
        std::fill(row.begin(), row.end(), false);
      }
    }

    finished = true;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        grid[i][j]--;

        if (grid[i][j] <= 0) {
          land[i][j] = false;
          changed = true;
        }

        if (land[i][j]) {
          finished = false;
        }
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
  for (auto &row : grid) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
