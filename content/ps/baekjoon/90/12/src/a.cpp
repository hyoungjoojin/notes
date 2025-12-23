#include <iostream>
#include <stack>

bool solution(std::string &input) {
  std::stack<int> stack;

  for (char ch : input) {
    if (ch == '(') {
      stack.push(1);
    } else {
      if (stack.empty()) {
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

  int n = 0;
  std::cin >> n;

  std::string input;
  while (n--) {
    std::cin >> input;
    std::cout << (solution(input) ? "YES\n" : "NO\n");
  }

  return 0;
}
