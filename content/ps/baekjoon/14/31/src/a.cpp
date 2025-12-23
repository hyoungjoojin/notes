#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }

int sum(std::string &str) {
  int result = 0;
  for (char ch : str) {
    if (isDigit(ch)) {
      result += (ch - '0');
    }
  }
  return result;
}

void solution(std::vector<std::string> &strings) {
  std::sort(strings.begin(), strings.end(),
            [](std::string &s1, std::string &s2) {
              if (s1.length() != s2.length()) {
                return s1.length() < s2.length();
              }

              int sum1 = sum(s1), sum2 = sum(s2);
              if (sum1 != sum2) {
                return sum1 < sum2;
              }

              for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[i]) {
                  continue;
                }

                bool isDigit1 = isDigit(s1[i]);
                bool isDigit2 = isDigit(s2[i]);

                if (isDigit1 && isDigit2) {
                  return s1[i] < s2[i];
                } else if (isDigit1) {
                  return true;
                } else if (isDigit2) {
                  return false;
                }

                return s1 < s2;
              }
              return s1 < s2;
            });
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::string> strings(n);
  for (std::string &str : strings) {
    std::cin >> str;
  }

  solution(strings);
  for (std::string &str : strings) {
    std::cout << str << '\n';
  }

  return 0;
}
