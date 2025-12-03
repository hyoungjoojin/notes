#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution_(std::vector<int> &memo, std::vector<int> &array, int target) {
  if (target == 0) {
    return 0;
  }

  if (memo[target] != -1) {
    return memo[target];
  }

  int result = std::numeric_limits<int>::max();
  for (int i = 0; i < array.size(); i++) {
    if (target < i + 1) {
      continue;
    }

    result =
        std::min(result, solution_(memo, array, target - i - 1) + array[i]);
  }

  return memo[target] = result;
}

int solution(std::vector<int> &array) {
  int target = array.size();
  std::vector<int> memo(target + 1, -1);

  return solution_(memo, array, target);
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
