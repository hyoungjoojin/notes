#include <iostream>
#include <stack>
#include <string>

long long solution(std::string &parens) {
  long long count = 0;

  std::stack<int> stack;
  for (int i = 0; i < parens.size(); i++) {
    if (parens[i] == '(') {
      stack.push(1);
    } else {
      stack.pop();
      count += parens[i - 1] == '(' ? stack.size() : 1;
    }
  }

  return count;
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
