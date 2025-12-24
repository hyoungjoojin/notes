#include <iostream>

void solution_(int n) {
  if (n == 1) {
    std::cout << '-';
    return;
  }

  int next = n / 3;

  solution_(next);
  for (int i = 0; i < next; i++) {
    std::cout << ' ';
  }
  solution_(next);
}

void solution(int n) {
  int power = 1;
  while (n--) {
    power *= 3;
  }

  solution_(power);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  while (std::cin >> n) {
    solution(n);
    std::cout << '\n';
  }

  return 0;
}
