#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void solution(std::vector<int> &numbers) {
  std::sort(numbers.begin(), numbers.end(), std::greater<int>());
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

  solution(numbers);

  for (int number : numbers) {
    std::cout << number << '\n';
  }

  return 0;
}
