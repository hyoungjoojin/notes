#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> primes;

void fill_primes() {
  std::vector<bool> is_prime(123456 * 2 + 1, true);
  for (int i = 2; i * i < is_prime.size(); i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j < is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = 2; i < is_prime.size(); i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int solution(int n) {
  return std::upper_bound(primes.begin(), primes.end(), 2 * n) -
         std::lower_bound(primes.begin(), primes.end(), n + 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  fill_primes();

  int n = 0;
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }

    std::cout << solution(n) << '\n';
  }

  return 0;
}
