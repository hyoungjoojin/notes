#include <iostream>
#include <stack>
#include <vector>

std::vector<int> solution(std::vector<int> &heights) {
  std::vector<int> result(heights.size());

  std::stack<int> stack;
  for (int i = 0; i < heights.size(); i++) {
    while (!stack.empty() && heights[stack.top()] < heights[i]) {
      stack.pop();
    }

    result[i] = stack.empty() ? 0 : stack.top() + 1;
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
  for (int &h : heights) {
    std::cin >> h;
  }

  std::vector<int> result = solution(heights);
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
