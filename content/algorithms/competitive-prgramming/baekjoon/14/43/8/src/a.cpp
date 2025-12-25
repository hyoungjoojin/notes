#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void solution(std::vector<int> &array, int num_queries) {
  int size = 1;
  while (size < array.size()) {
    size *= 2;
  }

  std::vector<int> segtree(size * 2, std::numeric_limits<int>::max());
  for (int i = 0; i < array.size(); i++) {
    segtree[size + i] = array[i];
  }

  for (int i = size * 2 - 1; i > 1; i--) {
    segtree[i / 2] = std::min(segtree[i / 2], segtree[i]);
  }

  int command = 0, a = 0, b = 0;
  while (num_queries--) {
    std::cin >> command >> a >> b;

    if (command == 1) {
      int i = a + size - 1;
      segtree[i] = b;

      while (i) {
        i /= 2;
        segtree[i] = std::min(segtree[i * 2], segtree[i * 2 + 1]);
      }

      continue;
    }

    int result = std::numeric_limits<int>::max();
    for (int left = a + size - 1, right = b + size - 1; left <= right;) {
      if (left % 2 == 1) {
        result = std::min(result, segtree[left]);
      }

      if (right % 2 == 0) {
        result = std::min(result, segtree[right]);
      }

      left = (left + 1) / 2;
      right = (right - 1) / 2;
    }

    std::cout << result << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  int m = 0;
  std::cin >> m;

  solution(array, m);

  return 0;
}
