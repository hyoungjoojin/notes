#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::string solution(std::string &a_str, std::string &b_str) {
  std::vector<int> a, b, result;

  for (int i = a_str.size() - 1; i >= 0; i--) {
    a.push_back(a_str[i] - '0');
  }

  for (int i = b_str.size() - 1; i >= 0; i--) {
    b.push_back(b_str[i] - '0');
  }

  int i = 0, j = 0;
  bool carry = false;

  while (i < a.size() || j < b.size()) {
    int next = (carry ? 1 : 0);

    if (i < a.size()) {
      next += a[i++];
    }

    if (j < b.size()) {
      next += b[j++];
    }

    carry = (next >= 10);
    result.push_back(next % 10);
  }

  if (carry) {
    result.push_back(1);
  }

  for (int li = 0, ri = result.size() - 1; li <= ri; li++, ri--) {
    std::swap(result[li], result[ri]);
  }

  std::string result_str = "";
  for (int i : result) {
    result_str += (i + '0');
  }

  return result_str;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string a, b;
  std::cin >> a >> b;

  std::cout << solution(a, b) << '\n';

  return 0;
}
