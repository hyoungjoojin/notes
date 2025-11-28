#include <algorithm>
#include <iostream>
#include <string>

std::string solution(std::string &word) {
  std::string original = word;

  bool has_next = std::next_permutation(word.begin(), word.end());
  return has_next ? word : original;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::string word;
  while (t--) {
    std::cin >> word;
    std::cout << solution(word) << '\n';
  }

  return 0;
}
