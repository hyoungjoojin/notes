#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

int solution(std::vector<int> &array, int m) {
  int result = std::numeric_limits<int>::max();

  for (int li = 1, ri = std::reduce(array.begin(), array.end(), 0); li <= ri;) {
    int mid = (li + ri) / 2;

    int count = 0, current = 0;
    bool fit = true;

    for (int i : array) {
      if (i > mid) {
        fit = false;
        break;
      }

      current += i;

      if (current > mid) {
        current = i;
        count++;
      }
    }

    if (current > 0) {
      count++;
    }

    if (fit && count <= m) {
      result = std::min(result, mid);
      ri = mid - 1;
    } else {
      li = mid + 1;
    }
  }

  return result;
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

  std::cout << solution(array, m) << '\n';

  return 0;
}
