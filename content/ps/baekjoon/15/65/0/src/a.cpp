#include <iostream>
#include <vector>

void solution_(std::vector<bool> &selected, int n, int m, int min) {
  if (m == 0) {
    for (int i = 1; i <= n; i++) {
      if (selected[i]) {
        std::cout << i << ' ';
      }
    }
    std::cout << '\n';

    return;
  }

  for (int i = min; i <= n; i++) {
    if (selected[i]) {
      continue;
    }

    selected[i] = true;
    solution_(selected, n, m - 1, i + 1);
    selected[i] = false;
  }
}

void solution(int n, int m) {
  std::vector<bool> selected(n + 1, false);
  solution_(selected, n, m, 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  solution(n, m);

  return 0;
}
