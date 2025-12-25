#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int solution(int n, std::vector<int> &target) {
  std::queue<int> queue;
  for (int i = 1; i <= n; i++) {
    queue.push(i);
  }

  int count = 0;
  for (int i : target) {
    int moved = 0, size = queue.size();

    while (queue.front() != i) {
      queue.push(queue.front());
      queue.pop();
      moved++;
    }

    queue.pop();
    count += std::min(moved, size - moved);
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> target(m);
  for (int &i : target) {
    std::cin >> i;
  }

  std::cout << solution(n, target) << '\n';

  return 0;
}
