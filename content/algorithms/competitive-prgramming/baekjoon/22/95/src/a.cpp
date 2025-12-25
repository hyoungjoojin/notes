#include <algorithm>
#include <iostream>
#include <vector>

long long solution(std::vector<long long> &array) {
  std::sort(array.begin(), array.end());

  std::vector<long long> sum;
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array.size(); j++) {
      sum.push_back(array[i] + array[j]);
    }
  }
  std::sort(sum.begin(), sum.end());

  for (int k = array.size() - 1; k >= 0; k--) {
    for (int c = 0; c < array.size(); c++) {
      long long target = array[k] - array[c];

      if (std::binary_search(sum.begin(), sum.end(), target)) {
        return array[k];
      }
    }
  }

  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<long long> array(n);
  for (long long &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
