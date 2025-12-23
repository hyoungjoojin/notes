#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution(std::vector<int> &colors, int total) {
  int result = std::numeric_limits<int>::max();

  for (int li = 1, ri = *std::max_element(colors.begin(), colors.end());
       li <= ri;) {
    int mid = (li + ri) / 2;

    int count = 0;
    for (int c : colors) {
      count += (c / mid);
      count += (c % mid != 0 ? 1 : 0);
    }

    if (count > total) {
      li = mid + 1;
    } else {
      result = std::min(result, mid);
      ri = mid - 1;
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

  std::vector<int> colors(m);
  for (int &i : colors) {
    std::cin >> i;
  }

  std::cout << solution(colors, n) << '\n';

  return 0;
}
