#include <iostream>
#include <stack>
#include <utility>
#include <vector>

int solution(std::vector<std::pair<int, int>> &points) {
  points.push_back({-1, 0});

  std::stack<int> stack;

  int count = 0;
  for (auto &[x, y] : points) {
    while (!stack.empty()) {
      if (stack.top() > y) {
        stack.pop();
        count++;
      } else if (stack.top() == y) {
        stack.pop();
      } else {
        break;
      }
    }

    stack.push(y);
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> points(n);
  for (auto &[x, y] : points) {
    std::cin >> x >> y;
  }

  std::cout << solution(points) << '\n';

  return 0;
}
