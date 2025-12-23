#include <iostream>
#include <utility>

std::pair<int, int> solution(int x) {
  if (x == 0) {
    return {1, 0};
  } else if (x == 1) {
    return {0, 1};
  }

  std::pair<int, int> first = {1, 0}, second = {0, 1}, result = {0, 0};
  for (int i = 2; i <= x; i++) {
    result.first = first.first + second.first;
    result.second = first.second + second.second;

    first.first = second.first;
    first.second = second.second;

    second.first = result.first;
    second.second = result.second;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int x = 0;
  while (t--) {
    std::cin >> x;
    auto [a, b] = solution(x);
    std::cout << a << ' ' << b << '\n';
  }

  return 0;
}
