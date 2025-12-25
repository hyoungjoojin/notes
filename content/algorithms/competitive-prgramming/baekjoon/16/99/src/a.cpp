#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 1000000;

int solution_(std::vector<int> &cache, int n) {
  if (cache[n] != -1) {
    return cache[n];
  }

  int result = INF;
  for (int i = 1; i * i <= n; i++) {
    result = std::min(solution_(cache, n - i * i) + 1, result);
  }

  return cache[n] = result;
}

int solution(int n) {
  std::vector<int> cache(n + 1, -1);
  cache[0] = 0;
  cache[1] = 1;

  return solution_(cache, n);
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
