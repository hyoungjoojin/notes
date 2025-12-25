#include <iostream>
#include <queue>
#include <vector>

int solution(int n, int start, int target, int up, int down) {
  std::vector<int> distance(n + 1, -1);
  std::queue<int> queue;

  int dy[2] = {up, -down};

  distance[start] = 0;
  queue.push(start);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int d : dy) {
      int next = front + d;
      if (next <= 0 || next > n || distance[next] != -1) {
        continue;
      }

      distance[next] = distance[front] + 1;
      queue.push(next);
    }
  }

  return distance[target];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int f = 0, s = 0, g = 0, u = 0, d = 0;
  std::cin >> f >> s >> g >> u >> d;

  int result = solution(f, s, g, u, d);
  if (result == -1) {
    std::cout << "use the stairs\n";
  } else {
    std::cout << result << '\n';
  }

  return 0;
}
