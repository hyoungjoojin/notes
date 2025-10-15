#include <algorithm>
#include <iostream>
#include <vector>

long solution(std::vector<long> &heights, long target) {
  long result = 0;

  for (long li = 0, ri = *std::max_element(heights.begin(), heights.end());
       li <= ri;) {
    long mid = (li + ri) / 2;

    long sum = 0;
    for (long h : heights) {
      sum += std::max(h - mid, 0L);
    }

    if (sum >= target) {
      result = std::max(mid, result);
      li = mid + 1;
    } else {
      ri = mid - 1;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  long m = 0;
  std::cin >> n >> m;

  std::vector<long> array(n);
  for (long &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array, m) << '\n';

  return 0;
}
