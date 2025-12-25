#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  auto cmp = [](int x1, int x2) {
    int a1 = std::abs(x1), a2 = std::abs(x2);
    return (a1 != a2 ? a1 > a2 : x1 > x2);
  };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

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
