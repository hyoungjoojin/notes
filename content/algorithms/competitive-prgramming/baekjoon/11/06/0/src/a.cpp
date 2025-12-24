#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution_(std::vector<int> &memo, std::vector<int> &array, int index) {
  if (memo[index] != -1) {
    return memo[index];
  }

  if (index == array.size() - 1) {
    return 0;
  }

  int result = std::numeric_limits<int>::max();

  for (int i = 1; i <= array[index]; i++) {
    if (index + i >= array.size()) {
      break;
    }

    int next = solution_(memo, array, index + i);
    if (next == -1) {
      continue;
    }

    result = std::min(result, next + 1);
  }

  if (result == std::numeric_limits<int>::max()) {
    result = -1;
  }

  return memo[index] = result;
}

int solution(std::vector<int> &array) {
  std::vector<int> memo(array.size(), -1);
  return solution_(memo, array, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
