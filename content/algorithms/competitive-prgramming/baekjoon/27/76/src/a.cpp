#include <iostream>
#include <unordered_map>
#include <vector>

void solution(std::vector<int> &input, std::vector<int> &target) {
  std::unordered_map<int, int> hash_table;
  for (int i : input) {
    hash_table[i] = 1;
  }

  for (int i : target) {
    std::cout << hash_table[i] << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::vector<int> input, target;
  int n = 0;
  while (t--) {
    std::cin >> n;
    input.resize(n);
    for (int &i : input) {
      std::cin >> i;
    }

    std::cin >> n;
    target.resize(n);
    for (int &i : target) {
      std::cin >> i;
    }

    solution(input, target);
  }

  return 0;
}
