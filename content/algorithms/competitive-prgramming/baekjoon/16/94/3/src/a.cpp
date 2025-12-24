#include <algorithm>
#include <iostream>
#include <vector>

int solution(int a, int b) {
  int c = -1;

  std::vector<int> digits;
  while (a) {
    digits.push_back(a % 10);
    a /= 10;
  }

  std::sort(digits.begin(), digits.end());

  do {
    int number = 0;

    if (digits[0] == 0) {
      continue;
    }

    for (int i = digits.size() - 1, tens = 1; i >= 0; i--, tens *= 10) {
      number += (tens * digits[i]);
    }

    if (number >= b) {
      break;
    } else {
      c = std::max(c, number);
    }
  } while (std::next_permutation(digits.begin(), digits.end()));

  return c;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0;
  std::cin >> a >> b;

  std::cout << solution(a, b) << '\n';

  return 0;
}
