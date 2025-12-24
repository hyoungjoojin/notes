#include <iostream>
#include <vector>

void multiply(const std::vector<std::vector<int>> &a,
              const std::vector<std::vector<int>> &b,
              std::vector<std::vector<int>> &result) {
  int n = result.size();
  std::vector<std::vector<int>> array(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        array[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = array[i][j] % 1000;
    }
  }
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> &array,
                                       long long b) {
  int n = array.size();
  std::vector<std::vector<std::vector<int>>> memo;

  std::vector<std::vector<int>> initial(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      initial[i][j] = array[i][j];
    }
  }
  memo.push_back(initial);

  for (long long i = 1; (1L << i) <= b; i++) {
    std::vector<std::vector<int>> squared(n, std::vector<int>(n));
    multiply(memo[i - 1], memo[i - 1], squared);
    memo.push_back(squared);
  }

  std::vector<std::vector<int>> result(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = (i == j) ? 1 : 0;
    }
  }

  bool first = true;

  for (long long t = b, i = 0; t > 0; t >>= 1, i++) {
    if (t & 1) {
      multiply(result, memo[i], result);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  long long b = 0;
  std::cin >> n >> b;

  std::vector<std::vector<int>> array(n, std::vector<int>(n));
  for (auto &row : array) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::vector<std::vector<int>> result = solution(array, b);
  for (auto &row : result) {
    for (int &i : row) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
