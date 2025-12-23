#include <iostream>
#include <string>

std::string solution(int k) {
  int length = 1, remainder = k, power = 2;
  while (remainder > power) {
    length++;
    remainder -= power;
    power *= 2;
  }

  remainder--;

  std::string result = "";
  for (int i = 0; i < length; i++) {
    result += '4';
  }

  int index = length - 1;
  while (remainder) {
    if (remainder & 1) {
      result[index] = '7';
    }

    remainder = remainder / 2;
    index--;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
