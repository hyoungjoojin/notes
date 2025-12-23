#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string solution(const std::vector<int> &array) {
  std::stack<int> stack;
  std::string result = "";

  int maximum = 0;
  for (int number : array) {
    if (maximum < number) {
      for (int i = maximum + 1; i <= number; i++) {
        stack.push(i);
        result += "+\n";
      }

      maximum = number;
    }

    bool found = false;
    while (!stack.empty()) {
      int top = stack.top();
      stack.pop();

      if (top == number) {
        found = true;
        result += "-\n";
        break;
      }
    }

    if (!found) {
      return "NO\n";
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &number : array) {
    std::cin >> number;
  }

  std::cout << solution(array);

  return 0;
}
