#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

long long solution(std::vector<std::pair<long long, long long>> &lines) {
  std::sort(lines.begin(), lines.end());
  lines.push_back({std::numeric_limits<long long>::max(),
                   std::numeric_limits<long long>::max()});

  long long result = 0, left = std::numeric_limits<long long>::min(),
            right = std::numeric_limits<long long>::min();
  for (auto &[x, y] : lines) {
    if (x <= right) {
      right = std::max(right, y);
    } else {
      result += (right - left);
      left = x;
      right = y;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<long long, long long>> lines(n);
  for (auto &[x, y] : lines) {
    std::cin >> x >> y;
  }

  std::cout << solution(lines) << '\n';

  return 0;
}
