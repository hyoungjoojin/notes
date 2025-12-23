#include <iostream>

int solution(int n) {
  for (int i = 1; i <= n; i++) {
    int sum = i, t = i;
    while (t) {
      sum += t % 10;
      t /= 10;
    }

    if (sum == n) {
      return i;
    }
  }

  return 0;
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
