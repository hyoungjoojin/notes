# Competitive Programming

---

**Question**

Given two strings $s$ and $t$, write a function that can find all starting indices of the substrings in $s$ that are equal
to $t$.

**Answer**

- Knuth-Morris-Pratt (KMP) Algorithm

  ```c++
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
  ```

---
