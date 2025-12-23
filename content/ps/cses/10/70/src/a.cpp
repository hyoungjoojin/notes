#include <iostream>

void solution(int n) {
  if (n == 1) {
    std::cout << "1\n";
    return;
  } else if (n < 4) {
    std::cout << "NO SOLUTION\n";
    return;
  }

  for (int i = 2; i <= n; i += 2) {
    std::cout << i << ' ';
  }

  for (int i = 1; i <= n; i += 2) {
    std::cout << i << ' ';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}
