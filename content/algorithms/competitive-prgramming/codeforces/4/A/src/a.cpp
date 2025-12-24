#include <iostream>

bool solution(int n) { return n > 2 && n % 2 == 0; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << (solution(n) ? "YES\n" : "NO\n");

  return 0;
}
