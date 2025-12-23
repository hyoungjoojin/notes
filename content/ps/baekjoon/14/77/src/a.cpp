#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution(std::vector<int> &breakpoints, int new_breakpoints,
             int total_length) {
  std::sort(breakpoints.begin(), breakpoints.end());

  int result = std::numeric_limits<int>::max();

  for (int li = 1, ri = total_length; li <= ri;) {
    int mid = (li + ri) / 2;

    int required_breakpoints = 0, x = 0;
    for (int x = 0, i = 0; x <= total_length;) {
      if (x + mid >= total_length) {
        break;
      }

      if (i < breakpoints.size() && x + mid >= breakpoints[i]) {
        x = breakpoints[i++];
        continue;
      }

      required_breakpoints++;
      x += mid;
    }

    if (required_breakpoints <= new_breakpoints) {
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

  int n = 0, m = 0, l = 0;
  std::cin >> n >> m >> l;

  std::vector<int> current(n);
  for (int &i : current) {
    std::cin >> i;
  }

  std::cout << solution(current, m, l) << '\n';

  return 0;
}
