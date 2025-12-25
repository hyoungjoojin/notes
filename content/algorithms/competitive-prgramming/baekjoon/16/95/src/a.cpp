#include <algorithm>
#include <iostream>
#include <vector>

int solution_(std::vector<int> &numbers, std::vector<std::vector<int>> &cache,
              int start, int end) {
  if (start >= end) {
    return 0;
  }

  if (cache[start][end] != -1) {
    return cache[start][end];
  }

  if (numbers[start] == numbers[end]) {
    return cache[start][end] = solution_(numbers, cache, start + 1, end - 1);
  }

  return cache[start][end] =
             1 + std::min(solution_(numbers, cache, start + 1, end),
                          solution_(numbers, cache, start, end - 1));
}

int solution(std::vector<int> &numbers) {
  std::vector<std::vector<int>> cache(numbers.size(),
                                      std::vector<int>(numbers.size(), -1));

  return solution_(numbers, cache, 0, numbers.size() - 1);
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
