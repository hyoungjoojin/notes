#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array, int target) {
  std::sort(array.begin(), array.end());

  int count = 1, closest = std::abs(target - array[0] + array[1]);

  for (int i = 0; i < array.size(); i++) {
    for (int li = i + 1, ri = array.size() - 1; li <= ri;) {
      int mid = (li + ri) / 2;

      int sum = array[i] + array[mid];
      int diff = std::abs(target - sum);

      if (diff == closest) {
        count++;
      } else if (diff < closest) {
        count = 1;
        closest = diff;
      }

      if (sum >= target) {
        ri = mid - 1;
      } else {
        li = mid + 1;
      }
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0, k = 0;
  std::vector<int> array;

  while (t--) {
    std::cin >> n >> k;

    array.resize(n);
    for (int &i : array) {
      std::cin >> i;
    }

    std::cout << solution(array, k) << '\n';
  }

  return 0;
}
