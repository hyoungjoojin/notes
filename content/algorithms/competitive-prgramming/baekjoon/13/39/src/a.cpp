#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int solution(std::vector<std::string> &words) {
  std::array<int, 26> characters = {0};
  for (std::string &word : words) {
    for (int i = word.size() - 1, value = 1; i >= 0; i--, value *= 10) {
      characters[word[i] - 'A'] += value;
    }
  }

  std::sort(characters.begin(), characters.end(), std::greater<>());

  int result = 0;
  for (int i = 0, value = 9; i < characters.size(); i++, value--) {
    result += value * characters[i];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::string> words(n);
  for (std::string &s : words) {
    std::cin >> s;
  }

  std::cout << solution(words) << '\n';

  return 0;
}
