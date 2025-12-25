#include <algorithm>
#include <iostream>
#include <vector>

int solution(int total, std::vector<int> &values) {
  int result = 0;
  for (int li = 0, ri = total; li <= ri;) {
    int mid = (li + ri) / 2;

    int sum = 0, max_allocated = 0;
    for (int i : values) {
      int allocated = std::min(i, mid);
      max_allocated = std::max(max_allocated, allocated);
      sum += allocated;
    }

    if (sum <= total) {
      li = mid + 1;
      result = std::max(result, max_allocated);
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
  std::cin >> n;

  std::vector<int> values(n);
  for (int &i : values) {
    std::cin >> i;
  }

  int total = 0;
  std::cin >> total;

  std::cout << solution(total, values) << '\n';

  return 0;
}
