#include <iostream>

int solution(long x) {
  int flips = 0;

  while (x > 1) {
    long power = 1;
    while (power * 2 < x) {
      power *= 2;
    }

    x -= power;
    flips++;
  }

  return flips % 2;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
