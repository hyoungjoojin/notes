#include <iostream>
#include <queue>
#include <vector>

int solution(int a, int b, int start, int end) {
  std::vector<int> distance(100001, -1);
  std::queue<int> queue;

  int d[] = {1, -1, a, -a, -b, b};
  int m[] = {a, b};

  queue.push(start);
  distance[start] = 0;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == end) {
      break;
    }

    for (int &dx : d) {
      int next_x = front + dx;
      if (next_x < 0 || next_x >= distance.size() || distance[next_x] != -1) {
        continue;
      }

      queue.push(next_x);
      distance[next_x] = distance[front] + 1;
    }

    for (int &mx : m) {
      int next_x = front * mx;
      if (next_x >= distance.size() || distance[next_x] != -1) {
        continue;
      }

      queue.push(next_x);
      distance[next_x] = distance[front] + 1;
    }
  }

  return distance[end];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, n = 0, m = 0;
  std::cin >> a >> b >> n >> m;

  std::cout << solution(a, b, n, m) << '\n';

  return 0;
}
