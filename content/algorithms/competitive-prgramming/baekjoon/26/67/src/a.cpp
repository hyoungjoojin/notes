#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &grid) {
  int n = grid.size();
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::vector<int> result;
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0 || visited[i][j]) {
        continue;
      }

      int size = 1;
      queue.push({i, j});
      visited[i][j] = true;

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (auto &[dr, dc] : d) {
          int next_r = r + dr, next_c = c + dc;

          if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n ||
              grid[next_r][next_c] == 0 || visited[next_r][next_c]) {
            continue;
          }

          size++;
          queue.push({next_r, next_c});
          visited[next_r][next_c] = true;
        }
      }

      result.push_back(size);
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

  std::string input;
  for (auto &row : grid) {
    std::cin >> input;

    for (int i = 0; i < n; i++) {
      row[i] = input[i] - '0';
    }
  }

  std::vector<int> result = solution(grid);
  std::sort(result.begin(), result.end());

  std::cout << result.size() << '\n';
  for (int i : result) {
    std::cout << i << '\n';
  }

  return 0;
}
