#include <iostream>
#include <utility>

std::pair<int, int> solution(int d, int k) {
  std::pair<int, int> f_a = {1, 0}, f_b = {0, 1}, f_t;
  for (int i = 3; i <= d; i++) {
    f_t.first = f_a.first + f_b.first;
    f_t.second = f_a.second + f_b.second;

    f_a.first = f_b.first;
    f_a.second = f_b.second;

    f_b.first = f_t.first;
    f_b.second = f_t.second;
  }

  int a = f_t.first, b = f_t.second;

  for (int x = 1, remainder = k - a; remainder >= 0; x++, remainder -= a) {
    if (remainder % b == 0) {
      return {x, remainder / b};
    }
  }

  return {0, 0};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int d = 0, k = 0;
  std::cin >> d >> k;

  auto [f0, f1] = solution(d, k);
  std::cout << f0 << '\n' << f1 << '\n';

  return 0;
}
