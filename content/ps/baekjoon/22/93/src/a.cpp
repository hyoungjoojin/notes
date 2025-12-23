#include <iostream>
#include <vector>

int solution(std::vector<int> &coins, int target) {
  std::vector<int> result(target + 1);

  result[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= target; i++) {
      result[i] += result[i - coin];
    }
  }

  return result[target];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<int> coins(n);
  for (int &i : coins) {
    std::cin >> i;
  }

  std::cout << solution(coins, k) << '\n';

  return 0;
}
