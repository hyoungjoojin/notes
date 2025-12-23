#include <array>
#include <iostream>

int sum(std::array<int, 10> &array, int to) {
  int result = 0;
  for (int i = 0; i < to; i++) {
    result = (result + array[i]) % 10007;
  }

  return result;
}

int solution(int n) {
  std::array<int, 10> result, temp;
  for (int i = 0; i < 10; i++) {
    result[i] = 1;
  }

  for (int len = 1; len < n; len++) {
    for (int i = 0; i < 10; i++) {
      temp[i] = sum(result, i + 1);
    }

    for (int i = 0; i < 10; i++) {
      result[i] = temp[i];
    }
  }

  return sum(result, 10);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
