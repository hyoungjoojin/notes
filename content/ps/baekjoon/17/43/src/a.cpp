#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<bool>> &grid) {
  int result = 0;

  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (visited[i][j] || !grid[i][j]) {
        continue;
      }

      int size = 1;
      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (auto &[dr, dc] : d) {
          int next_r = r + dr, next_c = c + dc;
          if (next_r < 0 || next_r >= grid.size() || next_c < 0 ||
              next_c >= grid[0].size() || visited[next_r][next_c] ||
              !grid[next_r][next_c]) {
            continue;
          }

          size++;
          visited[next_r][next_c] = true;
          queue.push({next_r, next_c});
        }
      }

      if (size > result) {
        result = size;
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0, k = 0;
  std::cin >> n >> m >> k;

  std::vector<std::vector<bool>> grid(n + 1, std::vector<bool>(m + 1, false));

  int r = 0, c = 0;
  while (k--) {
    std::cin >> r >> c;
    grid[r][c] = true;
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
