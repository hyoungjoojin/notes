#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int solution_(std::vector<std::pair<int, int>> &array, int sum, int mul,
              int count, int index) {
  if (index == array.size()) {
    return count == 0 ? -1 : std::abs(sum - mul);
  }

  int take = solution_(array, sum + array[index].second,
                       mul * array[index].first, count + 1, index + 1),
      skip = solution_(array, sum, mul, count, index + 1);

  if (skip == -1) {
    return take;
  }

  return std::min(take, skip);
}

int solution(std::vector<std::pair<int, int>> &array) {
  return solution_(array, 0, 1, 0, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> array(n);
  for (auto &[s, b] : array) {
    std::cin >> s >> b;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
