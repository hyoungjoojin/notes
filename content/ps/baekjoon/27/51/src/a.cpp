#include <algorithm>
#include <iostream>
#include <vector>

void solution(std::vector<int> &numbers) {
  std::sort(numbers.begin(), numbers.end());
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

  solution(numbers);

  for (int i : numbers) {
    std::cout << i << '\n';
  }

  return 0;
}
