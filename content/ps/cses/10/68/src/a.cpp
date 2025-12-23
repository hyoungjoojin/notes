#include <iostream>

void solution(long long n) {
  while (n != 1) {
    std::cout << n << ' ';

    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
  }

  std::cout << "1\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}
