#include <iostream>
#include <vector>

int solution(std::vector<int> &coins, int target) {
  int result = 0;
  for (auto it = coins.rbegin(); it != coins.rend(); it++) {
    result += (target / *it);
    target %= *it;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<int> coins(n);
  for (int &coin : coins) {
    std::cin >> coin;
  }

  std::cout << solution(coins, k) << '\n';

  return 0;
}
