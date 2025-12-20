#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  std::queue<std::pair<int, int>> queue;

  int num_components = 0;
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

  int t = 0;
  std::cin >> t;

  int m = 0, n = 0, k = 0;

  while (t--) {
    std::cin >> m >> n >> k;
    std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

    int x = 0, y = 0;
    while (k--) {
      std::cin >> x >> y;
      grid[x][y] = 1;
    }

    std::cout << solution(grid) << '\n';
  }

  return 0;
}
