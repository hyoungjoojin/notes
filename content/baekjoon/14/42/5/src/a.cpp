#include <iostream>
#include <unordered_map>

bool solution(std::unordered_map<std::string, int> &dictionary,
              std::string &target) {
  return dictionary.find(target) != dictionary.end();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::unordered_map<std::string, int> dictionary;

  std::string word;
  while (n--) {
    std::cin >> word;
    dictionary[word] = 1;
  }

  int count = 0;
  while (m--) {
    std::cin >> word;
    if (solution(dictionary, word)) {
      count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
