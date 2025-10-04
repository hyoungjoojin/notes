#include <iostream>
#include <stack>
#include <string>

bool solution(std::string &input) {
  std::stack<char> stack;

  for (char ch : input) {
    if (ch == '(' || ch == '[') {
      stack.push(ch);
    } else if (ch == ')') {
      if (stack.empty() || stack.top() != '(') {
        return false;
      }

      stack.pop();
    } else if (ch == ']') {
      if (stack.empty() || stack.top() != '[') {
        return false;
      }

      stack.pop();
    }
  }

  return stack.empty();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  while (std::getline(std::cin, input)) {
    if (input == ".") {
      break;
    }

    std::cout << (solution(input) ? "yes\n" : "no\n");
  }

  return 0;
}
