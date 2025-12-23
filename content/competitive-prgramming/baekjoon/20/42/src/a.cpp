#include <iostream>
#include <vector>

void solution(std::vector<long long> &array, int num_queries) {
  int size = 1;
  while (size < array.size()) {
    size *= 2;
  }

  std::vector<long long> segment_tree(size * 2);
  for (int i = 0; i < array.size(); i++) {
    segment_tree[i + size] = array[i];
  }

  for (int i = size * 2 - 1; i > 1; i--) {
    segment_tree[i / 2] += segment_tree[i];
  }

  int query;
  long long a, b;
  while (num_queries--) {
    std::cin >> query >> a >> b;

    if (query == 1) {
      int index = a + size - 1;
      long long add = b, subtract = segment_tree[index];

      while (index) {
        segment_tree[index] += add;
        segment_tree[index] -= subtract;
        index /= 2;
      }
      continue;
    }

    long long result = 0;
    int start = a + size - 1, end = b + size - 1;

    while (start <= end) {
      if (start % 2 == 1) {
        result += segment_tree[start];
      }

      if (end % 2 == 0) {
        result += segment_tree[end];
      }

      start = (start + 1) / 2;
      end = (end - 1) / 2;
    }

    std::cout << result << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0, k = 0;
  std::cin >> n >> m >> k;

  std::vector<long long> array(n);
  for (long long &i : array) {
    std::cin >> i;
  }

  solution(array, m + k);

  return 0;
}
