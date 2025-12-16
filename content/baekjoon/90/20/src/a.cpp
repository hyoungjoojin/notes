#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<bool> is_prime(10001);

void fill_primes() {
  std::fill(is_prime.begin(), is_prime.end(), true);

  is_prime[0] = false;
  is_prime[1] = false;

  for (int i = 2; i * i < is_prime.size(); i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j < is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }
}

std::pair<int, int> solution(int n) {
  for (int li = n / 2; li >= 0; li--) {
    if (is_prime[li] && is_prime[n - li]) {
      return {li, n - li};
    }
  }

  return {0, 0};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  fill_primes();

  int t = 0;
  std::cin >> t;

  int n = 0;
  while (t--) {
    std::cin >> n;

    auto [p1, p2] = solution(n);
    std::cout << p1 << ' ' << p2 << '\n';
  }

  return 0;
}
