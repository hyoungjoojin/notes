#include <iostream>
#include <stack>
#include <string>

int priority(char ch) {
  switch (ch) {
  case '(':
    return 0;

  case '+':
  case '-':
    return 1;

  case '*':
  case '/':
    return 2;

  default:
    return 3;
  }
}

std::string solution(std::string &expression) {
  std::stack<std::string> exp_stack;
  std::stack<char> op_stack;

  for (char ch : expression) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      while (!op_stack.empty()) {
        char op = op_stack.top();
        if (priority(op) < priority(ch)) {
          break;
        }

        op_stack.pop();

        std::string b = exp_stack.top();
        exp_stack.pop();

        std::string a = exp_stack.top();
        exp_stack.pop();

        a += b;
        a += op;
        exp_stack.push(a);
      }

      op_stack.push(ch);
    } else if (ch == '(') {
      op_stack.push('(');
    } else if (ch == ')') {
      while (!op_stack.empty()) {
        char op = op_stack.top();
        op_stack.pop();
        if (op == '(') {
          break;
        }

        std::string b = exp_stack.top();
        exp_stack.pop();

        std::string a = exp_stack.top();
        exp_stack.pop();

        a += b;
        a += op;
        exp_stack.push(a);
      }
    } else {
      exp_stack.push(std::string(1, ch));
    }
  }

  while (!op_stack.empty()) {
    char op = op_stack.top();
    op_stack.pop();

    std::string b = exp_stack.top();
    exp_stack.pop();

    std::string a = exp_stack.top();
    exp_stack.pop();

    a += b;
    a += op;
    exp_stack.push(a);
  }

  return exp_stack.top();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string expression;
  std::cin >> expression;

  std::cout << solution(expression) << '\n';

  return 0;
}
