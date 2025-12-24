#include <iostream>
#include <utility>
#include <vector>

void solution(std::vector<int> &array, int num_queries) {
  int size = 1;
  while (size < array.size()) {
    size *= 2;
  }

  std::vector<long long> segtree(size * 2, 0);

  int command, i, j;
  while (num_queries--) {
    std::cin >> command >> i >> j;

    if (command == 0) {
      if (j < i) {
        std::swap(i, j);
      }

      long long result = 0;

      for (int left = i + size - 1, right = j + size - 1; left <= right;) {
        if (left % 2 == 1) {
          result += segtree[left];
        }

        if (right % 2 == 0) {
          result += segtree[right];
        }

        left = (left + 1) / 2;
        right = (right - 1) / 2;
      }

      std::cout << result << '\n';

    } else {
      long long add = j, subtract = segtree[i + size - 1];

      for (int x = i + size - 1; x >= 1; x /= 2) {
        segtree[x] += add;
        segtree[x] -= subtract;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> array(n + 1, 0);

  solution(array, m);

  return 0;
}
