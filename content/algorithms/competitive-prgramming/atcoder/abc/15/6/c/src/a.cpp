#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution(std::vector<int> &coordinates) {
  int min = std::numeric_limits<int>::max();
  for (int i = 1; i <= 100; i++) {
    int sum = 0;
    for (int c : coordinates) {
      sum += (c - i) * (c - i);
    }

    min = std::min(min, sum);
  }

  return min;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> coordinates(n);
  for (int &coordinate : coordinates) {
    std::cin >> coordinate;
  }

  std::cout << solution(coordinates) << '\n';

  return 0;
}
