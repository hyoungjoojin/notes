#include <iostream>
#include <vector>

int solution(long long min, long long max) {
  std::vector<bool> divisible(max - min + 1, false);
  for (long long i = 2; i * i <= max; i++) {
    long long square = i * i;
    for (long long j =
             (min / square) * square + (min % square == 0 ? 0 : square);
         j <= max; j += square) {
      divisible[j - min] = true;
    }
  }

  int count = 0;
  for (int i = 0; i < divisible.size(); i++) {
    if (!divisible[i]) {
      count++;
    }
  }
  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long min, max;
  std::cin >> min >> max;

  std::cout << solution(min, max) << '\n';

  return 0;
}
