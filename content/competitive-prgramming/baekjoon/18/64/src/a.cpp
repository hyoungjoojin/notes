#include <iostream>

int chtoi(char c) {
  switch (c) {
  case '\\':
    return 1;
  case '(':
    return 2;
  case '@':
    return 3;
  case '?':
    return 4;
  case '>':
    return 5;
  case '&':
    return 6;
  case '%':
    return 7;
  case '/':
    return -1;
  case '-':
  default:
    return 0;
  }
}

int solution(std::string &number) {
  int result = 0;
  for (char ch : number) {
    result += chtoi(ch);
    result *= 8;
  }
  result /= 8;

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string number;
  while (true) {
    std::cin >> number;
    if (number == "#") {
      break;
    }

    std::cout << solution(number) << '\n';
  }

  return 0;
}
