#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string solution(std::vector<std::string> &names,
                     std::unordered_map<std::string, int> &reverseNames,
                     std::string query) {
  bool isNumber = query[0] >= '0' && query[0] <= '9';

  if (isNumber) {
    int index = std::stoi(query);
    return names[index - 1];
  } else {
    return std::to_string(reverseNames[query]);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, q = 0;
  std::cin >> n >> q;

  std::vector<std::string> names(n);
  std::unordered_map<std::string, int> reverseNames;

  for (int i = 0; i < n; i++) {
    std::cin >> names[i];
    reverseNames[names[i]] = i + 1;
  }

  std::string query = "";
  while (q--) {
    std::cin >> query;
    std::cout << solution(names, reverseNames, query) << '\n';
  }

  return 0;
}
