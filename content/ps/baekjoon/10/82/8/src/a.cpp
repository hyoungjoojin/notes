#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::stack<int> stack;

  std::vector<int> buffer;
  buffer.reserve(n);

  std::string command;
  int value = 0;
  while (n--) {
    std::cin >> command;

    if (command == "push") {
      std::cin >> value;
      stack.push(value);

    } else if (command == "pop") {
      if (!stack.empty()) {
        buffer.push_back(stack.top());
        stack.pop();
      } else {
        buffer.push_back(-1);
      }
    } else if (command == "size") {
      buffer.push_back(stack.size());
    } else if (command == "empty") {
      buffer.push_back(stack.empty() ? 1 : 0);
    } else if (command == "top") {
      buffer.push_back(stack.empty() ? -1 : stack.top());
    }
  }

  for (int value : buffer) {
    std::cout << value << '\n';
  }

  return 0;
}
