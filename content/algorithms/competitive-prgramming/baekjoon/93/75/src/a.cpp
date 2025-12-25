#include <iostream>
#include <string>
#include <unordered_map>

int solution(int n) {
  std::unordered_map<std::string, int> count;

  std::string _, type;
  while (n--) {
    std::cin >> _ >> type;
    count[type]++;
  }

  int result = 1;
  for (auto &[_, c] : count) {
    result *= (c + 1);
  }
  return result - 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  while (t--) {
    std::cin >> n;
    std::cout << solution(n) << '\n';
  }

  return 0;
}
