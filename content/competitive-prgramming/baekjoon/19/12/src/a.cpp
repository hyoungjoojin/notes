#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &numbers) {
  int curmax = numbers[0], max = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    curmax = std::max(numbers[i], numbers[i] + curmax);
    max = std::max(max, curmax);
  }

  return max;
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

  std::cout << solution(numbers) << '\n';

  return 0;
}
