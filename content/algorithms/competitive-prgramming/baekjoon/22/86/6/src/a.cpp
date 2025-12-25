#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stack>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> solution(std::vector<int> &heights) {
  std::vector<std::pair<int, int>> result(heights.size(),
                                          {0, std::numeric_limits<int>::max()});

  std::stack<int> stack;
  for (int i = 0; i < heights.size(); i++) {
    while (!stack.empty() && heights[stack.top()] <= heights[i]) {
      stack.pop();
    }

    result[i].first += stack.size();

    if (!stack.empty()) {
      result[i].second = std::min(result[i].second, stack.top());
    }

    stack.push(i);
  }

  while (!stack.empty()) {
    stack.pop();
  }

  for (int i = heights.size() - 1; i >= 0; i--) {
    while (!stack.empty() && heights[stack.top()] <= heights[i]) {
      stack.pop();
    }

    result[i].first += stack.size();

    if (!stack.empty() &&
        std::abs(stack.top() - i) < std::abs(result[i].second - i)) {
      result[i].second = stack.top();
    }

    stack.push(i);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int &height : heights) {
    std::cin >> height;
  }

  std::vector<std::pair<int, int>> result = solution(heights);
  for (auto &[count, min] : result) {
    if (count == 0) {
      std::cout << "0\n";
    } else {
      std::cout << count << ' ' << min + 1 << '\n';
    }
  }

  return 0;
}
