#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> primes;

int solution(int n) {
  int count = 0;
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] * 2 > n) {
      break;
    }

    if (std::binary_search(primes.begin() + i, primes.end(), n - primes[i])) {
      count++;
    }
  }

  return count;
}

void find_primes() {
  std::vector<bool> is_prime(1000001, true);

  for (int i = 2; i * i <= is_prime.size(); i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j <= is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = 2; i <= is_prime.size(); i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  find_primes();

  int t = 0;
  std::cin >> t;

  int input = 0;
  while (t--) {
    std::cin >> input;
    std::cout << solution(input) << '\n';
  }

  return 0;
}
