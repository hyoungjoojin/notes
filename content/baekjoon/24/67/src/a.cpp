#include <cstdlib>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

std::pair<long, long> solution(std::vector<long> &array) {
  long min = std::numeric_limits<long>::max();
  long a, b;

  for (int i = 0; i < array.size(); i++) {
    for (int li = i + 1, ri = array.size() - 1; li <= ri;) {
      int mid = (li + ri) / 2;

      long sum = array[i] + array[mid];
      if (min > std::abs(sum)) {
        min = std::abs(sum);
        a = i;
        b = mid;
      }

      if (sum > 0) {
        ri = mid - 1;
      } else {
        li = mid + 1;
      }
    }
  }

  return {array[a], array[b]};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<long> array(n);
  for (long &i : array) {
    std::cin >> i;
  }

  auto [x, y] = solution(array);
  std::cout << x << ' ' << y << '\n';

  return 0;
}
