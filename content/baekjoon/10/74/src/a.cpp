#include <iostream>

int solution_(int size, int r, int c, int base) {
  if (size == 1) {
    return base;
  }

  int half_size = size / 2;
  int block = half_size * half_size;

  if (r >= half_size) {
    r -= half_size;
    base += block * 2;
  }

  if (c >= half_size) {
    c -= half_size;
    base += block;
  }

  return solution_(half_size, r, c, base);
}

int solution(int n, int r, int c) {
  int size = 1 << n;
  return solution_(size, r, c, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, r = 0, c = 0;
  std::cin >> n >> r >> c;

  std::cout << solution(n, r, c) << '\n';

  return 0;
}
