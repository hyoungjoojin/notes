#include <iostream>
#include <vector>

long long solution(std::vector<int> &array) {
  long long result = 0;

  for (int i = 1; i < array.size(); i++) {
    if (array[i] < array[i - 1]) {
      result += (array[i - 1] - array[i]);
      array[i] = array[i - 1];
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

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
