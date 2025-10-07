#include <iostream>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::unordered_map<std::string, int> hash_table;

  std::string name;
  for (int i = 0; i < n; i++) {
    std::cin >> name;
    hash_table[name]++;
  }

  for (int i = 1; i < n; i++) {
    std::cin >> name;
    hash_table[name]--;
  }

  for (auto &[name, c] : hash_table) {
    if (c == 1) {
      std::cout << name << '\n';
      break;
    }
  }

  return 0;
}
