#include <iomanip>
#include <ios>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

double solution(std::string &expression, std::vector<int> &values) {
  std::stack<double> stack;

  for (char ch : expression) {
    if ('A' <= ch && ch <= 'Z') {
      stack.push(values[ch - 'A']);
      continue;
    }

    double a = stack.top();
    stack.pop();

    double b = stack.top();
    stack.pop();

    double c;
    switch (ch) {
    case '+':
      c = a + b;
      break;
    case '-':
      c = b - a;
      break;
    case '*':
      c = a * b;
      break;
    case '/':
      c = b / a;
      break;
    }

    stack.push(c);
  }

  return stack.top();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::string expression;
  std::cin >> expression;

  std::vector<int> values(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i];
  }

  std::cout << std::fixed << std::setprecision(2)
            << solution(expression, values) << '\n';

  return 0;
}
