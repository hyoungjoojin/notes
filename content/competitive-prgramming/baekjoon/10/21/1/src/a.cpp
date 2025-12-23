#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &input) {
  int max = input[0], curmax = input[0];
  for (int i = 1; i < input.size(); i++) {
    curmax = std::max(curmax + input[i], input[i]);
    max = std::max(max, curmax);
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::vector<int> input;
  int n = 0;

  while (t--) {
    std::cin >> n;
    input.resize(n);

    for (int &i : input) {
      std::cin >> i;
    }

    std::cout << solution(input) << '\n';
  }

  return 0;
}
