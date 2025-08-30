#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &prices) {
  std::vector<int> memo(prices.size() + 1);

  for (int i = 1; i <= prices.size(); i++) {
    int max = 0;

    for (int j = 0; j < prices.size(); j++) {
      if (i - j < 1) {
        continue;
      }

      max = std::max(max, memo[i - j - 1] + prices[j]);
    }

    memo[i] = max;
  }

  return memo[prices.size()];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }

  std::cout << solution(p) << '\n';

  return 0;
}
