#include <iostream>
#include <queue>

int solution(int n) {
  std::queue<int> queue;

  for (int i = 1; i <= n; i++) {
    queue.push(i);
  }

  while (queue.size() > 1) {
    queue.pop();
    queue.push(queue.front());
    queue.pop();
  }

  return queue.front();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
