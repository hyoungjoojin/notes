#include <iostream>
#include <stack>
#include <string>

std::string solution(std::string &input) {
  std::stack<char> left, right;
  for (char ch : input) {
    if (ch == '<') {
      if (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    } else if (ch == '>') {
      if (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    } else if (ch == '-') {
      if (!left.empty()) {
        left.pop();
      }
    } else {
      left.push(ch);
    }
  }

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  std::string output;
  while (!right.empty()) {
    output += right.top();
    right.pop();
  }
  return output;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::string input;
  while (t--) {
    std::cin >> input;
    std::cout << solution(input) << '\n';
  }

  return 0;
}
