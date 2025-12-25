#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(int n, int k) {
  std::queue<int> queue;

  for (int i = 1; i <= n; i++) {
    queue.push(i);
  }

  std::vector<int> result(n);
  int index = 0;

  while (!queue.empty()) {
    for (int i = 1; i < k; i++) {
      queue.push(queue.front());
      queue.pop();
    }

    result[index++] = queue.front();
    queue.pop();
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<int> result = solution(n, k);

  std::cout << '<';
  for (int i = 0; i < n - 1; i++) {
    std::cout << result[i] << ", ";
  }
  std::cout << result[n - 1] << ">\n";

  return 0;
}
