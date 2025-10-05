#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>

void solution(std::map<std::string, int> &count) {
  std::cout << std::fixed << std::setprecision(4);

  int total_count = 0;
  for (auto &[key, c] : count) {
    total_count += c;
  }

  for (auto &[key, c] : count) {
    std::cout << key << ' ' << (double)c / total_count * 100 << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::map<std::string, int> count;

  std::string input;
  while (std::getline(std::cin, input)) {
    count[input]++;
  }

  solution(count);

  return 0;
}
