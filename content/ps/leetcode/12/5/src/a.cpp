#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string cleaned = "";
    for (char ch : s) {
      if ('A' <= ch && ch <= 'Z') {
        cleaned += (ch - 'A' + 'a');
      } else if ('a' <= ch && ch <= 'z') {
        cleaned += ch;
      } else if ('0' <= ch && ch <= '9') {
        cleaned += ch;
      }
    }
    for (int li = 0, ri = cleaned.length() - 1; li < ri; li++, ri--) {
      if (cleaned[li] != cleaned[ri]) {
        return false;
      }
    }

    return true;
  }
};
