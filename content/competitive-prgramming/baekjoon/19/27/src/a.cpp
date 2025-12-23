#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  int command = 0;
  while (n--) {
    std::cin >> command;

    if (command == 0) {
      if (pq.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(command);
    }
  }

  return 0;
}
