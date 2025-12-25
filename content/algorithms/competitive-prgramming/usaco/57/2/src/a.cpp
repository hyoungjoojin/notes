#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

void solution(const std::vector<std::array<int, 3>> &ptable,
              std::array<int, 3> &result, int start, int end) {
  start--;
  end--;

  for (int i = 0; i < 3; i++) {
    result[i] = ptable[end][i] - (start - 1 < 0 ? 0 : ptable[start - 1][i]);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  int n = 0, q = 0;
  std::cin >> n >> q;

  std::vector<int> breeds(n);
  for (int &breed : breeds) {
    std::cin >> breed;
  }

  std::vector<std::array<int, 3>> ptable(n);
  for (int i = 0; i < n; i++) {
    ptable[i][breeds[i] - 1] = 1;
  }

  for (int b = 0; b < 3; b++) {
    for (int i = 1; i < n; i++) {
      ptable[i][b] += ptable[i - 1][b];
    }
  }

  std::array<int, 3> result;
  int a, b;

  while (q--) {
    std::cin >> a >> b;

    solution(ptable, result, a, b);

    for (int i = 0; i < 3; i++) {
      std::cout << result[i] << (i == 2 ? '\n' : ' ');
    }
  }

  return 0;
}
