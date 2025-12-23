#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &top, std::vector<int> &bottom) {
  std::vector<std::vector<int>> memo(top.size(), std::vector<int>(3, 0));

  memo[0][0] = 0;
  memo[0][1] = top[0];
  memo[0][2] = bottom[0];

  for (int i = 1; i < top.size(); i++) {
    memo[i][0] = *std::max_element(memo[i - 1].begin(), memo[i - 1].end());
    memo[i][1] = std::max(memo[i - 1][0], memo[i - 1][2]) + top[i];
    memo[i][2] = std::max(memo[i - 1][0], memo[i - 1][1]) + bottom[i];
  }

  return *std::max_element(memo[top.size() - 1].begin(),
                           memo[top.size() - 1].end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  std::vector<int> top, bottom;

  while (t--) {
    std::cin >> n;

    top.resize(n);
    bottom.resize(n);

    for (int &i : top) {
      std::cin >> i;
    }

    for (int &i : bottom) {
      std::cin >> i;
    }

    std::cout << solution(top, bottom) << '\n';
  }

  return 0;
}
