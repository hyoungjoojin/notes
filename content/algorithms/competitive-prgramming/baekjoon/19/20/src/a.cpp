#include <algorithm>
#include <iostream>
#include <vector>

bool solution(const std::vector<int> &numbers, int target) {
  return std::binary_search(numbers.begin(), numbers.end(), target);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &number : numbers) {
    std::cin >> number;
  }

  std::sort(numbers.begin(), numbers.end());

  int m = 0;
  std::cin >> m;

  int target;
  while (m--) {
    std::cin >> target;
    std::cout << (solution(numbers, target) ? "1\n" : "0\n");
  }

  return 0;
}
