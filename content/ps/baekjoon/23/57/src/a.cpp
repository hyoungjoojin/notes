#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void solution(std::vector<int> &array, int num_queries) {
  int size = 1;
  while (size < array.size()) {
    size *= 2;
  }

  std::vector<int> min_segtree(size * 2, std::numeric_limits<int>::max()),
      max_segtree(size * 2, std::numeric_limits<int>::min());

  for (int i = 0; i < array.size(); i++) {
    min_segtree[i + size] = array[i];
    max_segtree[i + size] = array[i];
  }

  for (int i = size * 2 - 1; i > 1; i--) {
    min_segtree[i / 2] = std::min(min_segtree[i / 2], min_segtree[i]);
    max_segtree[i / 2] = std::max(max_segtree[i / 2], max_segtree[i]);
  }

  int a = 0, b = 0;
  while (num_queries--) {
    std::cin >> a >> b;

    int min = std::numeric_limits<int>::max(),
        max = std::numeric_limits<int>::min();
    for (int left = a + size - 1, right = b + size - 1; left <= right;) {
      if (left % 2 == 1) {
        min = std::min(min, min_segtree[left]);
        max = std::max(max, max_segtree[left]);
      }

      if (right % 2 == 0) {
        min = std::min(min, min_segtree[right]);
        max = std::max(max, max_segtree[right]);
      }

      left = (left + 1) / 2;
      right = (right - 1) / 2;
    }

    std::cout << min << ' ' << max << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  solution(array, m);

  return 0;
}
