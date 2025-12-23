#include <iostream>

int cache[11] = {0};

int solution(int n) {
  if (cache[n] != 0) {
    return cache[n];
  }

  if (n <= 3) {
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    return cache[n];
  }

  return cache[n] = solution(n - 1) + solution(n - 2) + solution(n - 3);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  while (t--) {
    std::cin >> n;
    std::cout << solution(n) << '\n';
  }

  return 0;
}
