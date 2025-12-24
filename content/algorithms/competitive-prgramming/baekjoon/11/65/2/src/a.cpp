#include <algorithm>
#include <iostream>
#include <vector>

long long solution(std::vector<long long> &numbers) {
  std::sort(numbers.begin(), numbers.end());

  long long current = numbers[0], result = numbers[0];
  int count = 1, count_max = 1;

  for (int i = 1; i < numbers.size(); i++) {
    if (current == numbers[i]) {
      count++;
      continue;
    }

    if (count_max < count) {
      count_max = count;
      result = current;
    }

    current = numbers[i];
    count = 1;
  }

  if (count_max < count) {
    count_max = count;
    result = current;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<long long> numbers(n);
  for (long long &number : numbers) {
    std::cin >> number;
  }

  std::cout << solution(numbers) << '\n';

  return 0;
}
