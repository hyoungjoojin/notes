#include <algorithm>
#include <cstdio>
#include <iostream>

int solution(int x, int y, int m) {
  int max = 0;

  for (int i = 0; i <= m; i += x) {
    max = std::max(max, m - (m - i) % y);
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x = 0, y = 0, m = 0;
  std::cin >> x >> y >> m;

  std::cout << solution(x, y, m) << '\n';

  return 0;
}
