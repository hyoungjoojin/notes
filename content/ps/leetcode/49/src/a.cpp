#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;

    unordered_map<string, int> map;

    string sorted = "";
    for (string &s : strs) {
      sorted = s;
      sort(sorted.begin(), sorted.end());

      if (map.find(sorted) != map.end()) {
        map[sorted] = result.size();

        vector<string> entry;
        entry.push_back(s);
        result.push_back(entry);
      } else {
        result[map[sorted]].push_back(s);
      }
    }

    return result;
  }
};
