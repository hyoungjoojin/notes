#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solution(std::vector<std::vector<char>> &grid, bool blind) {
  std::queue<std::pair<int, int>> queue;
  std::vector<std::vector<bool>> visited(grid.size(),
                                         std::vector<bool>(grid.size(), false));

  int num_components = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid.size(); j++) {
      if (visited[i][j]) {
        continue;
      }

      num_components++;
      queue.push({i, j});
      visited[i][j] = true;

      while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop();

        for (auto &[dx, dy] : d) {
          int next_x = x + dx, next_y = y + dy;
          if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
              next_y >= grid.size() || visited[next_x][next_y]) {
            continue;
          }

          if (grid[x][y] == grid[next_x][next_y] ||
              (blind && (grid[x][y] == 'R' && grid[next_x][next_y] == 'G' ||
                         grid[x][y] == 'G' && grid[next_x][next_y] == 'R'))) {
            queue.push({next_x, next_y});
            visited[next_x][next_y] = true;
          }
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

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<char>> grid(n, std::vector<char>(n));
  for (auto &row : grid) {
    for (char &ch : row) {
      std::cin >> ch;
    }
  }

  std::cout << solution(grid, false) << ' ' << solution(grid, true) << '\n';

  return 0;
}
