#include <iostream>
#include <vector>

long long solution_(std::vector<std::vector<long long>> &memo,
                    std::vector<int> &array, int last, int target) {
  if (target > 20 || target < 0) {
    return 0;
  }

  if (last == 0) {
    return array[0] == target ? 1 : 0;
  }

  if (memo[last][target] != -1) {
    return memo[last][target];
  }

  return memo[last][target] =
             solution_(memo, array, last - 1, target + array[last]) +
             solution_(memo, array, last - 1, target - array[last]);
}

long long solution(std::vector<int> &array) {
  std::vector<std::vector<long long>> memo(array.size(),
                                           std::vector<long long>(21, -1));
  solution_(memo, array, array.size() - 2, array[array.size() - 1]);
  for (long long &count : memo[array.size() - 2]) {
    if (count == -1) {
      count = 0;
    }
  }

  long long result = 0;
  for (long long count : memo[array.size() - 2]) {
    result += count;
  }
  return result;
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
