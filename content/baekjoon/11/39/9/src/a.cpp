#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array) {
  std::sort(array.begin(), array.end());

  int sum = 0, cumsum = 0;
  for (int i : array) {
    cumsum += i;
    sum += cumsum;
  }

  return sum;
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
