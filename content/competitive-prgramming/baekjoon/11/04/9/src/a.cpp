#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

int solution_(std::vector<std::pair<int, int>> &matrices,
              std::vector<std::vector<int>> &cache, int start, int end) {
  if (cache[start][end] != -1) {
    return cache[start][end];
  }

  if (start == end) {
    return cache[start][end] = 0;
  }

  int min = std::numeric_limits<int>::max(), cur = 0;
  for (int i = start + 1; i <= end; i++) {
    cur = solution_(matrices, cache, start, i - 1) +
          solution_(matrices, cache, i, end) +
          matrices[start].first * matrices[i].first * matrices[end].second;

    min = std::min(min, cur);
  }

  return cache[start][end] = min;
}

int solution(std::vector<std::pair<int, int>> &matrices) {
  std::vector<std::vector<int>> cache(matrices.size(),
                                      std::vector<int>(matrices.size(), -1));

  return solution_(matrices, cache, 0, matrices.size() - 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> matrices(n);
  for (auto &[r, c] : matrices) {
    std::cin >> r >> c;
  }

  std::cout << solution(matrices) << '\n';

  return 0;
}
