#include <iostream>

int solution(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  }

  int a = 1, b = 2, c = 0;
  for (int i = 1; i < n - 1; i++) {
    c = (a + b) % 10007;
    a = b % 10007;
    b = c;
  }

  return c;
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
