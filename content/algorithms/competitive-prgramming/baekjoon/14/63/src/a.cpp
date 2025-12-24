#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution(int n) {
  std::vector<int> result(n + 1, std::numeric_limits<int>::max());
  result[1] = 0;

  for (int i = 1; i < n; i++) {
    int next_value = result[i] + 1, next_index = i + 1;
    result[next_index] = std::min(next_value, result[next_index]);

    next_index += (i - 1);
    if (next_index > n) {
      continue;
    }
    result[next_index] = std::min(next_value, result[next_index]);

    next_index += i;
    if (next_index > n) {
      continue;
    }
    result[next_index] = std::min(next_value, result[next_index]);
  }

  return result[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
