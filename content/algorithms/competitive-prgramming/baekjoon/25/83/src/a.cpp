#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &grid) {
  int num_rows = grid.size(), num_cols = grid[0].size();

  std::queue<std::pair<int, int>> queue;
  std::vector<std::vector<int>> visited(num_rows,
                                        std::vector<int>(num_cols, 0));

  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::vector<int> result;

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (grid[i][j] == 0 || visited[i][j]) {
        continue;
      }

      int area = 1;
      queue.push({i, j});
      visited[i][j] = 1;

      while (!queue.empty()) {
        auto &[x, y] = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {
          int next_x = x + d[i][0], next_y = y + d[i][1];

          if (next_x < 0 || next_x >= num_rows || next_y < 0 ||
              next_y >= num_cols || visited[next_x][next_y] ||
              grid[next_x][next_y] == 0) {
            continue;
          }

          area++;
          queue.push({next_x, next_y});
          visited[next_x][next_y] = 1;
        }
      }

      result.push_back(area);
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

  std::vector<std::vector<int>> grid(n, std::vector<int>(m, 1));

  int x1, y1, x2, y2;
  while (k--) {
    std::cin >> x1 >> y1 >> x2 >> y2;

    for (int row = y1; row < y2; row++) {
      for (int col = x1; col < x2; col++) {
        grid[row][col] = 0;
      }
    }
  }

  std::vector<int> result = solution(grid);
  std::sort(result.begin(), result.end());

  std::cout << result.size() << '\n';
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
