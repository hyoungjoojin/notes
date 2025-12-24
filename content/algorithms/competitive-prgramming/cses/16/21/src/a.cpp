#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array) {
  std::sort(array.begin(), array.end());

  int count = 1;
  for (int i = 1; i < array.size(); i++) {
    if (array[i] != array[i - 1]) {
      count++;
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
