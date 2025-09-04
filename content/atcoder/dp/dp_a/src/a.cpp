#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

int solution(std::vector<int> &heights) {
  std::vector<int> result(heights.size(), std::numeric_limits<int>::max());
  result[0] = 0;

  for (int i = 0; i < heights.size(); i++) {
    if (i + 1 < heights.size()) {
      result[i + 1] = std::min(
          result[i + 1], result[i] + std::abs(heights[i + 1] - heights[i]));
    }

    if (i + 2 < heights.size()) {
      result[i + 2] = std::min(
          result[i + 2], result[i] + std::abs(heights[i + 2] - heights[i]));
    }
  }

  return result[heights.size() - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int &height : heights) {
    std::cin >> height;
  }

  std::cout << solution(heights) << '\n';

  return 0;
}
