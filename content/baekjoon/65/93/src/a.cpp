#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int solution(std::vector<std::vector<std::vector<char>>> &grid, int x, int y,
             int z) {
  std::vector<std::vector<std::vector<int>>> distance(
      x, std::vector<std::vector<int>>(y, std::vector<int>(z, -1)));
  std::queue<std::tuple<int, int, int>> queue;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        if (grid[i][j][k] == 'S') {
          distance[i][j][k] = 0;
          queue.push({i, j, k});
        }
      }
    }
  }

  int d[6][3] = {
      {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0},
  };

  while (!queue.empty()) {
    auto [a, b, c] = queue.front();
    queue.pop();

    if (grid[a][b][c] == 'E') {
      return distance[a][b][c];
    }

    for (auto &[da, db, dc] : d) {
      int next_a = a + da, next_b = b + db, next_c = c + dc;

      if (next_a >= 0 && next_a < x && next_b >= 0 && next_b < y &&
          next_c >= 0 && next_c < z && grid[next_a][next_b][next_c] != '#' &&
          distance[next_a][next_b][next_c] == -1) {
        distance[next_a][next_b][next_c] = distance[a][b][c] + 1;
        queue.push({next_a, next_b, next_c});
      }
    }
  }

  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  while (true) {
    int l = 0, r = 0, c = 0;
    std::cin >> l >> r >> c;

    if (l == 0 && r == 0 && c == 0) {
      break;
    }

    std::vector<std::vector<std::vector<char>>> grid(
        l, std::vector<std::vector<char>>(r, std::vector<char>(c)));
    for (auto &floor : grid) {
      for (auto &row : floor) {
        for (char &i : row) {
          std::cin >> i;
        }
      }
    }

    int distance = solution(grid, l, r, c);
    if (distance != -1) {
      std::cout << "Escaped in " << distance << " minute(s).\n";
    } else {
      std::cout << "Trapped!\n";
    }
  }

  return 0;
}
