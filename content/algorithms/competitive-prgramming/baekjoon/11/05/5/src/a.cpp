#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array) {
  std::vector<int> memo(array.size());

  memo[0] = array[0];

  for (int i = 1; i < array.size(); i++) {
    int max = array[i], current;

    for (int j = 0; j < i; j++) {
      current = (array[i] > array[j] ? array[i] + memo[j] : 0);

      if (max < current) {
        max = current;
      }
    }

    memo[i] = max;
  }

  return *std::max_element(memo.begin(), memo.end());
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
