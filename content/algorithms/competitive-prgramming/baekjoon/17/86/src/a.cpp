#include <iostream>
#include <string>
#include <vector>

std::vector<int> solution(std::string &haystack, std::string &needle) {
  std::vector<int> pi(needle.size(), 0);
  for (int i = 1; i < needle.size(); i++) {
    int j = pi[i - 1];
    while (j > 0 && needle[i] != needle[j]) {
      j = pi[j - 1];
    }

    if (needle[i] == needle[j]) {
      j++;
    }

    pi[i] = j;
  }

  std::vector<int> result;

  for (int i = 0, j = 0; i < haystack.size(); i++) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = pi[j - 1];
    }

    if (haystack[i] == needle[j]) {
      j++;
    }

    if (j == needle.size()) {
      result.push_back(i - j + 2);
      j = pi[j - 1];
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string t, p;

  std::getline(std::cin, t);
  std::getline(std::cin, p);

  std::vector<int> result = solution(t, p);

  std::cout << result.size() << '\n';
  for (int &i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
