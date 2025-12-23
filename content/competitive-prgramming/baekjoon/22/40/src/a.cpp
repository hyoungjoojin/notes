#include <algorithm>
#include <iostream>
#include <vector>

int solution_(std::vector<std::vector<std::vector<int>>> &memo,
              std::vector<int> &array, int t, int moves, int pos) {
  if (t == array.size()) {
    return 0;
  }

  if (memo[t][moves][pos] != -1) {
    return memo[t][moves][pos];
  }

  int result =
      solution_(memo, array, t + 1, moves, pos) + ((pos == array[t]) ? 1 : 0);

  if (moves > 0) {
    result =
        std::max(result, solution_(memo, array, t + 1, moves - 1, 3 - pos) +
                             (((3 - pos) == array[t]) ? 1 : 0));
  }

  return memo[t][moves][pos] = result;
}

int solution(std::vector<int> &array, int moves) {
  std::vector<std::vector<std::vector<int>>> memo(
      array.size(),
      std::vector<std::vector<int>>(moves + 1, std::vector<int>(3, -1)));

  return solution_(memo, array, 0, moves, 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0, w = 0;
  std::cin >> t >> w;

  std::vector<int> array(t);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array, w) << '\n';

  return 0;
}
