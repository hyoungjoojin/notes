#include <iostream>
#include <vector>

const int MOD = 1000000;

int solution_(std::vector<int> &memo, std::vector<int> &input, int start) {
  if (start == input.size()) {
    return 1;
  }

  if (memo[start] != -1) {
    return memo[start];
  }

  int result = 0;

  if (1 <= input[start] && input[start] <= 9) {
    result = solution_(memo, input, start + 1);
  }

  if (start + 1 < input.size()) {
    int number = 10 * input[start] + input[start + 1];
    if (10 <= number && number <= 26) {
      result += solution_(memo, input, start + 2);
      result %= MOD;
    }
  }

  result %= MOD;
  return memo[start] = result;
}

int solution(std::string &input) {
  std::vector<int> memo(input.size(), -1);

  std::vector<int> numbers(input.size());
  for (int i = 0; i < input.size(); i++) {
    numbers[i] = input[i] - '0';
  }

  return solution_(memo, numbers, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::cin >> input;

  std::cout << solution(input) << '\n';

  return 0;
}
