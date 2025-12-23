#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array, int target) {
  int max = 0;
  for (int li = 1, ri = *std::max_element(array.begin(), array.end());
       li <= ri;) {
    int mid = (li + ri) / 2;

    int sum = 0;
    for (int i : array) {
      sum += (i / mid);
    }

    if (sum >= target) {
      max = std::max(max, mid);
      li = mid + 1;
    } else {
      ri = mid - 1;
    }
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> m >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array, m) << '\n';

  return 0;
}
