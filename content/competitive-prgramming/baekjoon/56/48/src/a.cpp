#include <algorithm>
#include <iostream>
#include <vector>

void solution(std::vector<long long> &numbers) {
  for (long long &number : numbers) {
    long long temp = 0;
    while (number) {
      temp += number % 10;
      number /= 10;
      temp *= 10;
    }

    number = temp / 10;
  }

  std::sort(numbers.begin(), numbers.end());
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

  solution(numbers);
  for (long long number : numbers) {
    std::cout << number << "\n";
  }

  return 0;
}
