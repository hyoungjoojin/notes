#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<int>> &grid, int min, int max) {
  int days = 0;

  std::vector<std::vector<bool>> visited(grid.size(),
                                         std::vector<bool>(grid.size(), false));
  std::queue<std::pair<int, int>> queue, components;
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (true) {
    bool moved = false;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (visited[i][j]) {
          continue;
        }

        visited[i][j] = true;
        int sum = grid[i][j], count = 1;
        queue.push({i, j});
        components.push({i, j});

        while (!queue.empty()) {
          auto [r, c] = queue.front();
          queue.pop();

          for (auto &[dr, dc] : d) {
            int next_r = r + dr, next_c = c + dc;

            if (next_r < 0 || next_r >= grid.size() || next_c < 0 ||
                next_c >= grid.size() || visited[next_r][next_c]) {
              continue;
            }

            int diff = std::abs(grid[r][c] - grid[next_r][next_c]);
            if (diff < min || max < diff) {
              continue;
            }

            visited[next_r][next_c] = true;
            sum += grid[next_r][next_c];
            count++;
            queue.push({next_r, next_c});
            components.push({next_r, next_c});
          }
        }

        int new_value = sum / count;
        while (!components.empty()) {
          auto [r, c] = components.front();
          components.pop();

          if (grid[r][c] != new_value) {
            grid[r][c] = new_value;
            moved = true;
          }
        }
      }
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        visited[i][j] = false;
      }
    }

    if (!moved) {
      break;
    }

    days++;
  }

  return days;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, l = 0, r = 0;
  std::cin >> n >> l >> r;

  std::vector<std::vector<int>> grid(n, std::vector<int>(n));
  for (auto &row : grid) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::cout << solution(grid, l, r) << '\n';

  return 0;
}
