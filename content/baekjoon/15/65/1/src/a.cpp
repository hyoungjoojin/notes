#include <iostream>
#include <vector>

void solution_(std::vector<int> &slots, int start, int n) {
  if (start == slots.size()) {
    for (int i : slots) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    slots[start] = i;
    solution_(slots, start + 1, n);
  }
}

void solution(int n, int m) {
  std::vector<int> slots(m);
  solution_(slots, 0, n);
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
