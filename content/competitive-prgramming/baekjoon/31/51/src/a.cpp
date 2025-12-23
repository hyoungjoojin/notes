#include <algorithm>
#include <iostream>
#include <vector>

long long solution(std::vector<int> &array) {
  std::sort(array.begin(), array.end());

  long long count = 0;
  for (int i = 0; i < array.size(); i++) {
    for (int j = i + 1; j < array.size(); j++) {
      int target = -array[i] - array[j];
      count += (std::upper_bound(array.begin() + j + 1, array.end(), target) -
                std::lower_bound(array.begin() + j + 1, array.end(), target));
    }
  }

  return count;
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
