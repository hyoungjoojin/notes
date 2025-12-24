#include <iostream>
#include <vector>

long long solution(int n) {
  std::vector<long long> t(n + 1, 0);

  t[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      t[i] += t[j] * t[i - j - 1];
    }
  }

  return t[n];
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
