#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array, int k) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += array[i];
  }

  int max = sum, current = sum;
  for (int i = k; i < array.size(); i++) {
    current = current + array[i] - array[i - k];
    max = std::max(max, current);
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array, k) << '\n';

  return 0;
}
