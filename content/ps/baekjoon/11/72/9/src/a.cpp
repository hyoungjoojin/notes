#include <iostream>

void solution(int from, int to, int count) {
  if (count == 1) {
    std::cout << from << ' ' << to << '\n';
    return;
  }

  solution(from, 6 - from - to, count - 1);
  solution(from, to, 1);
  solution(6 - from - to, to, count - 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << (1 << n) - 1 << '\n';
  solution(1, 3, n);

  return 0;
}
