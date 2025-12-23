#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int solution(std::vector<long long> &psum) {
  int max = 0;

  long long sum;

  for (int i = 0; i < psum.size(); i++) {
    for (int j = i + max - 1; j < psum.size(); j++) {
      sum = psum[j] - (i == 0 ? 0 : psum[i - 1]);

      if (sum % 7 == 0) {
        max = std::max(max, j - i + 1);
      }
    }
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  int n = 0;
  std::cin >> n;

  std::vector<long long> psum(n);
  for (long long &id : psum) {
    std::cin >> id;
  }

  for (int i = 1; i < n; i++) {
    psum[i] += psum[i - 1];
  }

  std::cout << solution(psum) << '\n';

  return 0;
}
