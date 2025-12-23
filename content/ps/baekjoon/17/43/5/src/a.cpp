#include <iostream>
#include <vector>

void preprocess(std::vector<std::vector<int>> &table) {
  int n = table[0].size();

  for (int i = 1; i < table.size(); i++) {
    for (int j = 1; j < n; j++) {
      table[i][j] = table[i - 1][table[i - 1][j]];
    }
  }
}

int solution(std::vector<std::vector<int>> &table, int n, int x) {
  int result = x;

  for (int i = 0; n; i++, n /= 2) {
    if (n % 2 == 1) {
      result = table[i][result];
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m = 0;
  std::cin >> m;

  std::vector<std::vector<int>> table(31, std::vector<int>(m + 1, 0));
  for (int i = 1; i <= m; i++) {
    std::cin >> table[0][i];
  }

  preprocess(table);

  int q = 0;
  std::cin >> q;

  int n = 0, x = 0;
  while (q--) {
    std::cin >> n >> x;
    std::cout << solution(table, n, x) << '\n';
  }

  return 0;
}
