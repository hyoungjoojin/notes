#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array) {
  int max = 0;
  for (int li = 0, ri = array.size() - 1; li < ri;) {
    max = std::max(max, (ri - li - 1) * std::min(array[li], array[ri]));

    if (array[li] < array[ri]) {
      li++;
    } else {
      ri--;
    }
  }

  return max;
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
