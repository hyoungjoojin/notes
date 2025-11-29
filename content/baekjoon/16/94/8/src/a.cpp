#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(int n, int r1, int c1, int r2, int c2) {
  int d[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

  std::vector<std::vector<int>> distance(n, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> queue;

  distance[r1][c1] = 0;
  queue.push({r1, c1});

  while (!queue.empty()) {
    auto [r, c] = queue.front();
    queue.pop();

    for (auto &[dr, dc] : d) {
      int next_r = r + dr, next_c = c + dc;

      if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n ||
          distance[next_r][next_c] != -1) {
        continue;
      }

      distance[next_r][next_c] = distance[r][c] + 1;
      queue.push({next_r, next_c});
    }
  }

  return distance[r2][c2];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  int r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;

  std::cout << solution(n, r1, c1, r2, c2) << '\n';

  return 0;
}
