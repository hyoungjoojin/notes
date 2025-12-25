#include <cassert>
#include <vector>

/**
 * @brief Implementation of the Knuth-Morris-Pratt (KMP) algorithm
 *
 * @param haystack The string to search within.
 * @param needle The substring to search for.
 *
 * @return The list of starting indices of all occurrences of the needle in the
 * haystack. The indices are 0-based.
 */
std::vector<int> kmp(const std::string &haystack, const std::string &needle) {
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
      result.push_back(i - j + 1);
      j = pi[j - 1];
    }
  }

  return result;
}

int main() {
  std::string haystack = "ABCDABECDEBCDABECAABECD";
  std::string needle = "ABECD";

  std::vector<int> expected = {4, 18}, actual = kmp(haystack, needle);

  assert(expected.size() == actual.size());
  for (int i = 0; i < expected.size(); i++) {
    assert(expected[i] == actual[i]);
  }

  return 0;
}
