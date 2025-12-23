#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> solution(std::vector<int> array, int window) {
  int maximum = 0, maximum_count = 0, current = 0;

  for (int i = 0; i < window; i++) {
    current += array[i];
  }

  maximum = current;
  maximum_count = 1;

  for (int i = window; i < array.size(); i++) {
    current = current + array[i] - array[i - window];

    if (current > maximum) {
      maximum = current;
      maximum_count = 1;
    } else if (current == maximum) {
      maximum_count++;
    }
  }

  return {maximum, maximum_count};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, x = 0;
  std::cin >> n >> x;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  auto [max, count] = solution(array, x);

  if (max == 0) {
    std::cout << "SAD\n";
  } else {
    std::cout << max << '\n' << count << '\n';
  }

  return 0;
}
