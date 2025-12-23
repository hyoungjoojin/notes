#include <iostream>
#include <queue>
#include <vector>

int solution(int start, int target) {
  std::vector<int> distance(100001, -1);
  std::queue<int> queue;

  distance[start] = 0;
  queue.push(start);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == target) {
      return distance[target];
    }

    int next = front * 2;
    if (next < distance.size() && distance[next] == -1) {
      distance[next] = distance[front];
      queue.push(next);
    }

    next = front - 1;
    if (next >= 0 && distance[next] == -1) {
      distance[next] = distance[front] + 1;
      queue.push(next);
    }

    next = front + 1;
    if (next < distance.size() && distance[next] == -1) {
      distance[next] = distance[front] + 1;
      queue.push(next);
    }
  }

  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::cout << solution(n, k) << '\n';

  return 0;
}
