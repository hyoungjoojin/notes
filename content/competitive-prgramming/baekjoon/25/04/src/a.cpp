#include <iostream>
#include <stack>
#include <string>
#include <utility>

int solution(std::string &input) {
  int result = 0;

  std::stack<std::pair<int, char>> stack;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '(') {
      stack.push({2 * (stack.empty() ? 1 : stack.top().first), '('});
    } else if (input[i] == ')') {
      if (stack.empty() || stack.top().second != '(') {
        return 0;
      }

      if (input[i - 1] == '(') {
        result += stack.top().first;
      }
      stack.pop();

    } else if (input[i] == '[') {
      stack.push({3 * (stack.empty() ? 1 : stack.top().first), '['});

    } else if (input[i] == ']') {
      if (stack.empty() || stack.top().second != '[') {
        return 0;
      }

      if (input[i - 1] == '[') {
        result += stack.top().first;
      }
      stack.pop();
    }
  }

  if (!stack.empty()) {
    return 0;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::cin >> input;

  std::cout << solution(input) << '\n';

  return 0;
}
