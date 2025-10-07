#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::string solution(std::unordered_map<std::string, int> &titles) {
  std::vector<std::pair<std::string, int>> counts;
  for (auto &[title, count] : titles) {
    counts.push_back({title, count});
  }

  std::sort(
      counts.begin(), counts.end(),
      [](std::pair<std::string, int> &p1, std::pair<std::string, int> &p2) {
        if (p1.second == p2.second) {
          return p1.first > p2.first;
        }

        return p1.second < p2.second;
      });

  return counts[counts.size() - 1].first;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::unordered_map<std::string, int> hash_table;

  std::string title;
  while (n--) {
    std::cin >> title;
    hash_table[title]++;
  }

  std::cout << solution(hash_table) << '\n';

  return 0;
}
