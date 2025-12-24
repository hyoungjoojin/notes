#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int solution(std::vector<std::array<int, 3>> &costs) {
  if (costs.size() == 1) {
    return *std::min_element(costs[0].begin(), costs[0].end());
  }

  for (int i = 1; i < costs.size(); i++) {
    costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
    costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
    costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
  }

  return *std::min_element(costs[costs.size() - 1].begin(),
                           costs[costs.size() - 1].end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::array<int, 3>> costs(n);
  for (std::array<int, 3> &cost : costs) {
    std::cin >> cost[0] >> cost[1] >> cost[2];
  }

  std::cout << solution(costs) << '\n';

  return 0;
}
