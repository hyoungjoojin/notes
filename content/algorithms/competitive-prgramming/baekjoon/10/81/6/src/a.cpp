#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &numbers, int target) {
  return std::upper_bound(numbers.begin(), numbers.end(), target) -
         std::lower_bound(numbers.begin(), numbers.end(), target);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &i : numbers) {
    std::cin >> i;
  }

  std::sort(numbers.begin(), numbers.end());

  int m = 0;
  std::cin >> m;

  int target = 0;
  while (m--) {
    std::cin >> target;
    std::cout << solution(numbers, target) << '\n';
  }

  return 0;
}
