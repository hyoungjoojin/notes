#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int solution(std::vector<int> &array) {
  std::vector<std::pair<int, int>> memo(array.size());
  memo[0] = {array[0], 0};
  memo[1] = {array[0] + array[1], array[0]};

  for (int i = 2; i < array.size(); i++) {
    int take = std::max(memo[i - 2].first, memo[i - 2].second + array[i - 1]) +
               array[i];
    int not_take = std::max(memo[i - 1].first, memo[i - 1].second);

    memo[i] = {take, not_take};
  }

  return std::max(memo[array.size() - 1].first, memo[array.size() - 1].second);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
