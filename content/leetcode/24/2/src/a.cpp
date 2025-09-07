#include <array>
#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    std::array<int, 'z' - 'a' + 1> freq = {0};

    for (char ch : s) {
      freq[ch - 'a']++;
    }

    for (char ch : t) {
      freq[ch - 'a']--;
    }

    for (int i : freq) {
      if (i != 0) {
        return false;
      }
    }

    return true;
  }
};
