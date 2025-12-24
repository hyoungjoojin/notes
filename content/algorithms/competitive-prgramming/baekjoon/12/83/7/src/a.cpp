#include <iostream>
#include <vector>

void solution(std::vector<int> &array, int num_queries) {
  int size = 1;
  while (size < array.size()) {
    size *= 2;
  }

  std::vector<long long> segment_tree(size * 2, 0);

  int command, p, q;
  while (num_queries--) {
    std::cin >> command >> p >> q;

    if (command == 1) {
      for (int i = p + size - 1; i > 0; i /= 2) {
        segment_tree[i] += q;
      }
    } else {
      long long result = 0;
      for (int li = p + size - 1, ri = q + size - 1; li <= ri;) {
        if (li % 2 == 1) {
          result += segment_tree[li];
        }

        if (ri % 2 == 0) {
          result += segment_tree[ri];
        }

        li = (li + 1) / 2;
        ri = (ri - 1) / 2;
      }

      std::cout << result << '\n';
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, q = 0;
  std::cin >> n >> q;

  std::vector<int> array(n, 0);
  solution(array, q);

  return 0;
}
