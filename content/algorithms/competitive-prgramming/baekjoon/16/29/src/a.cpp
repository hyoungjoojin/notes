#include <iostream>

int solution(long long a, long long b, long long c) {
  long long result = 1;

  while (b) {
    if (b % 2 == 1) {
      result = (result * a) % c;
    }

    a = (a * a) % c;
    b /= 2;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;

  std::cout << solution(a, b, c) << '\n';

  return 0;
}
