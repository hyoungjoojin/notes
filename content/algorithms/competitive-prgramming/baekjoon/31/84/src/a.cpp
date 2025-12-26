#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::pair<int, int> solution(std::vector<std::vector<char>> &grid) {
  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  std::queue<std::pair<int, int>> queue;

  int total_sheep = 0, total_wolves = 0;
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (visited[i][j] || grid[i][j] == '#') {
        continue;
      }

      int sheep = 0, wolves = 0;

      visited[i][j] = true;
      queue.push({i, j});
      if (grid[i][j] == 'o') {
        sheep++;
      } else if (grid[i][j] == 'v') {
        wolves++;
      }

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (auto &[dr, dc] : d) {
          int next_r = r + dr, next_c = c + dc;

          if (next_r < 0 || next_r >= grid.size() || next_c < 0 ||
              next_c >= grid[0].size() || visited[next_r][next_c] ||
              grid[next_r][next_c] == '#') {
            continue;
          }

          visited[next_r][next_c] = true;
          queue.push({next_r, next_c});
          if (grid[next_r][next_c] == 'o') {
            sheep++;
          } else if (grid[next_r][next_c] == 'v') {
            wolves++;
          }
        }
      }

      if (sheep > wolves) {
        total_sheep += sheep;
      } else {
        total_wolves += wolves;
      }
    }
  }

  return {total_sheep, total_wolves};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int r = 0, c = 0;
  std::cin >> r >> c;

  std::vector<std::vector<char>> grid(r, std::vector<char>(c));

  std::string input;
  for (auto &row : grid) {
    std::cin >> input;
    for (int i = 0; i < c; i++) {
      row[i] = input[i];
    }
  }

  auto [sheep, wolves] = solution(grid);
  std::cout << sheep << ' ' << wolves << '\n';

  return 0;
}
