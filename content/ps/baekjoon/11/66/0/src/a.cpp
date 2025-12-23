#include <iostream>
#include <vector>

int solution(int x1, int y1, int x2, int y2,
             std::vector<std::vector<int>> &psum) {
  return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] +
         psum[x1 - 1][y1 - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> table(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> table[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
    }
  }

  int x1, y1, x2, y2;
  while (m--) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << solution(x1, y1, x2, y2, table) << "\n";
  }

  return 0;
}
