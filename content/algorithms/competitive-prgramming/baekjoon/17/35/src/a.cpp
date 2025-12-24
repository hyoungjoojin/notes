#include <algorithm>
#include <iostream>
#include <utility>

std::pair<int, int> solution(int a, int b, int c, int d) {
  int x = a * d + b * c, y = b * d;

  for (int i = 2; i * i <= std::max(x, y); i++) {
    while (x % i == 0 && y % i == 0) {
      x /= i;
      y /= i;
    }
  }

  return {x, y};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0, d = 0;
  std::cin >> a >> b >> c >> d;

  auto [x, y] = solution(a, b, c, d);
  std::cout << x << ' ' << y << '\n';

  return 0;
}
