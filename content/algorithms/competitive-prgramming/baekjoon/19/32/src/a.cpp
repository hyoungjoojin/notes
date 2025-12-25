#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<std::vector<int>> &triangle) {
  std::vector<int> memo(triangle.size(), 0), temp(triangle.size(), 0);

  memo[0] = triangle[0][0];

  for (int i = 1; i < triangle.size(); i++) {
    for (int j = 0; j <= i; j++) {
      int max = 0;

      if (j - 1 >= 0) {
        max = std::max(max, memo[j - 1]);
      }

      if (j < i) {
        max = std::max(max, memo[j]);
      }

      temp[j] = max + triangle[i][j];
    }

    for (int j = 0; j <= i; j++) {
      memo[j] = temp[j];
    }
  }

  return *std::max_element(memo.begin(), memo.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> triangle(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cin >> triangle[i][j];
    }
  }

  std::cout << solution(triangle) << '\n';

  return 0;
}
