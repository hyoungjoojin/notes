#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

int solution(std::vector<int> array) {
  int min = std::numeric_limits<int>::max(), result = 0;

  for (int i = 0; i < array.size(); i++) {
    for (int li = i + 1, ri = array.size() - 1; li <= ri;) {
      int mid = (li + ri) / 2;

      int sum = array[i] + array[mid];

      if (std::abs(sum) < min) {
        min = std::abs(sum);
        result = sum;
      }

      if (sum > 0) {
        ri = mid - 1;
      } else if (sum < 0) {
        li = mid + 1;
      } else {
        return 0;
      }
    }
  }

  return result;
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

  std::cout << solution(array) << '\n';

  return 0;
}
