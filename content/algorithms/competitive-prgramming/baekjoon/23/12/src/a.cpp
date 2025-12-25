#include <iostream>
#include <vector>

std::vector<int> primes;

void solution(int x) {
  for (int p : primes) {
    int count = 0;
    while (x % p == 0) {
      x /= p;
      count++;
    }

    if (count != 0) {
      std::cout << p << ' ' << count << '\n';
    }
  }
}

void fill_primes() {
  std::vector<bool> is_prime(100001, true);

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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  fill_primes();

  int t = 0;
  std::cin >> t;

  int input = 0;
  while (t--) {
    std::cin >> input;
    solution(input);
  }

  return 0;
}
