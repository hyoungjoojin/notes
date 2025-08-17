#include <iostream>
#include <vector>

void solution_recursive(std::vector<int> &slots, std::vector<bool> &used,
                        int index) {
  if (index == slots.size()) {
    for (int i : slots) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int i = 1; i < used.size(); i++) {
    if (used[i]) {
      continue;
    }

    used[i] = true;
    slots[index] = i;

    solution_recursive(slots, used, index + 1);

    used[i] = false;
  }
}

void solution(int n, int m) {
  std::vector<int> slots(m);
  std::vector<bool> used(n + 1, false);

  solution_recursive(slots, used, 0);
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
