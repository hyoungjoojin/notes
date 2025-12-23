#include <iostream>
#include <queue>
#include <vector>

int solution(int n, int k) {
  std::vector<int> distance(100001, -1);
  std::queue<int> queue;

  distance[n] = 0;
  queue.push(n);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == k) {
      return distance[front];
    }

    if (front + 1 < distance.size() && distance[front + 1] == -1) {
      distance[front + 1] = distance[front] + 1;
      queue.push(front + 1);
    }

    if (front - 1 >= 0 && distance[front - 1] == -1) {
      distance[front - 1] = distance[front] + 1;
      queue.push(front - 1);
    }

    if (front * 2 < distance.size() && distance[front * 2] == -1) {
      distance[front * 2] = distance[front] + 1;
      queue.push(front * 2);
    }
  }

  return -1;
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
