#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(int side, std::pair<int, int> &current,
             std::pair<int, int> &target) {
  int d[][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  std::vector<std::vector<int>> visited(side, std::vector<int>(side, -1));
  std::queue<std::pair<int, int>> queue;

  visited[current.first][current.second] = 0;
  queue.push(current);

  while (!queue.empty()) {
    auto &[x, y] = queue.front();
    queue.pop();

    if (x == target.first && y == target.second) {
      return visited[x][y];
    }

    for (auto &[dx, dy] : d) {
      int next_x = x + dx, next_y = y + dy;
      if (next_x < 0 || next_x >= side || next_y < 0 || next_y >= side ||
          visited[next_x][next_y] != -1) {
        continue;
      }

      visited[next_x][next_y] = visited[x][y] + 1;
      queue.push({next_x, next_y});
    }
  }

  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int side = 0;
  std::pair<int, int> current, target;

  while (t--) {
    std::cin >> side;
    std::cin >> current.first >> current.second;
    std::cin >> target.first >> target.second;

    std::cout << solution(side, current, target) << '\n';
  }

  return 0;
}
