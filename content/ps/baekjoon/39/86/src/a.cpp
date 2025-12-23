#include <iostream>
#include <stack>
#include <string>

bool solution(std::string &input) {
  std::stack<char> stack;

  for (char ch : input) {
    if (!stack.empty() && stack.top() == ch) {
      stack.pop();
    } else {
      stack.push(ch);
    }
  }

  return stack.empty();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  int result = 0;
  std::string input;

  while (n--) {
    std::cin >> input;
    result += (solution(input) ? 1 : 0);
  }

  std::cout << result << '\n';

  return 0;
}
