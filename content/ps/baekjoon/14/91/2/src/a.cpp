#include <iostream>

int solution(int n, int d) {
  int freq = 0;
  for (int i = 1; i <= n; i++) {
    int t = i;
    while (t) {
      if (d == t % 10) {
        freq++;
      }
      t /= 10;
    }
  }

  return freq;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, d = 0;
  std::cin >> n >> d;

  std::cout << solution(n, d) << '\n';

  return 0;
}
