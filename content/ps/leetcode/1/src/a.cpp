#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result(2, -1);

    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(target - nums[i]) != map.end()) {
        result[0] = i;
        result[1] = map[target - nums[i]];
        break;
      }

      map[nums[i]] = i;
    }

    return result;
  }
};
