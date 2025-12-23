#include <iostream>
#include <vector>

int solution(std::vector<int> &numbers, int n) {
  std::vector<int> found(n + 1, 0);
  for (int i : numbers) {
    found[i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (found[i] == 0) {
      return i;
    }
  }

  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n - 1);
  for (int &i : numbers) {
    std::cin >> i;
  }

  std::cout << solution(numbers, n) << '\n';

  return 0;
}
