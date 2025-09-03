#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int solution(std::vector<std::pair<int, int>> &points) {
  int max = 0, dx = 0, dy = 0;

  for (int i = 0; i < points.size(); i++) {
    for (int j = 0; j < points.size(); j++) {
      dx = (points[i].first - points[j].first);
      dy = (points[i].second - points[j].second);

      max = std::max(max, (dx * dx) + (dy * dy));
    }
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> points(n);

  for (int i = 0; i < n; i++) {
    std::cin >> points[i].first;
  }

  for (int i = 0; i < n; i++) {
    std::cin >> points[i].second;
  }

  std::cout << solution(points) << '\n';

  return 0;
}
