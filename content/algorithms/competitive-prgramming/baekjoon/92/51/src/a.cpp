#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int solution(const std::string &a, const std::string &b) {
  std::vector<std::vector<int>> memo(a.size() + 1,
                                     std::vector<int>(b.size() + 1, 0));

  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        memo[i][j] = memo[i - 1][j - 1] + 1;
      } else {
        memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
      }
    }
  }

  return memo[a.size()][b.size()];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string a, b;
  std::cin >> a >> b;

  std::cout << solution(a, b) << '\n';

  return 0;
}
