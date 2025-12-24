#include <array>
#include <iostream>

void solution(int n) {
  std::array<int, 10001> bins = {0};

  int number;
  while (n--) {
    std::cin >> number;
    bins[number]++;
  }

  for (int i = 0; i < bins.size(); i++) {
    for (int j = 0; j < bins[i]; j++) {
      std::cout << i << '\n';
    }
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
