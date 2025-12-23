#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using Grid = std::vector<std::vector<int>>;

void solution(Grid &grid, int num_rows, int num_cols) {
  int max_size = 0, num_components = 0;

  std::pair<int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  Grid visited(num_rows, std::vector<int>(num_cols, 0));
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (grid[i][j] == 0 || visited[i][j]) {
        continue;
      }

      num_components++;

      int size = 1;
      visited[i][j] = 1;
      queue.push({i, j});

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (auto &[dr, dc] : d) {
          int next_r = r + dr, next_c = c + dc;
          if (next_r < 0 || next_r >= num_rows || next_c < 0 ||
              next_c >= num_cols) {
            continue;
          }

          if (grid[next_r][next_c] == 0 || visited[next_r][next_c] == 1) {
            continue;
          }

          size++;
          visited[next_r][next_c] = 1;
          queue.push({next_r, next_c});
        }
      }

      max_size = std::max(max_size, size);
    }
  }

  std::cout << num_components << '\n';
  std::cout << max_size << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  Grid grid(n, std::vector<int>(m));
  for (std::vector<int> &row : grid) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  solution(grid, n, m);

  return 0;
}
