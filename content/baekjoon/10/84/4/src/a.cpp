#include <iostream>
#include <vector>

const int MOD = 1000000000;

int solution_(std::vector<std::vector<int>> &memo, int n, int start) {
  if (n == 1) {
    return 1;
  }

  if (memo[n][start] != -1) {
    return memo[n][start];
  }

  int result = 0;

  if (start + 1 <= 9) {
    result += solution_(memo, n - 1, start + 1);
    result %= MOD;
  }

  if (start - 1 >= 0) {
    result += solution_(memo, n - 1, start - 1);
    result %= MOD;
  }

  result %= MOD;
  return memo[n][start] = result;
}

int solution(int n) {
  std::vector<std::vector<int>> memo(n + 1, std::vector<int>(10, -1));

  int result = 0;
  for (int i = 1; i <= 9; i++) {
    result += solution_(memo, n, i);
    result %= MOD;
  }

  return result;
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
