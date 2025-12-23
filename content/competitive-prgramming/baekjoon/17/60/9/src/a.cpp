#include <algorithm>
#include <iostream>
#include <string>

int solution_(std::string &input, int start, int end, bool skipped) {
  if (start >= end) {
    return (skipped ? 1 : 0);
  }

  if (input[start] == input[end]) {
    return solution_(input, start + 1, end - 1, skipped);
  }

  if (skipped) {
    return 2;
  }

  return std::min(solution_(input, start, end - 1, true),
                  solution_(input, start + 1, end, true));
}

int solution(std::string &input) {
  return solution_(input, 0, input.size() - 1, false);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::string input;
  while (t--) {
    std::cin >> input;
    std::cout << solution(input) << '\n';
  }

  return 0;
}
