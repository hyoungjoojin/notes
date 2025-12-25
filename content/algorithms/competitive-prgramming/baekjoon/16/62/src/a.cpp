#include <iostream>
#include <stack>
#include <string>
#include <utility>

int solution(std::string &input) {
  std::stack<std::pair<int, char>> stack;

  for (char ch : input) {
    if (ch == '(') {
      stack.push({0, '('});
    } else if (ch == ')') {
      int total_length = 0;
      while (!stack.empty()) {
        auto [length, character] = stack.top();
        stack.pop();

        if (character == '(') {
          break;
        }

        total_length += length;
      }

      int repeat_count = stack.top().second - '0';
      stack.pop();

      stack.push({total_length * repeat_count, ' '});
    } else {
      stack.push({1, ch});
    }
  }

  int result = 0;
  while (!stack.empty()) {
    result += stack.top().first;
    stack.pop();
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
