#include <iostream>
#include <queue>
#include <unordered_map>

int solution(int a, int b) {
  std::unordered_map<long long, int> distance;
  std::queue<long long> queue;

  distance[a] = 1;
  queue.push(a);

  while (!queue.empty()) {
    long long front = queue.front();
    queue.pop();

    if (front == b) {
      return distance[front];
    }

    long long next = front * 2;
    if (next <= b && distance.find(next) == distance.end()) {
      distance[next] = distance[front] + 1;
      queue.push(next);
    }

    next = front * 10 + 1;
    if (next <= b && distance.find(next) == distance.end()) {
      distance[next] = distance[front] + 1;
      queue.push(next);
    }
  }

  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0;
  std::cin >> a >> b;

  std::cout << solution(a, b) << '\n';

  return 0;
}
