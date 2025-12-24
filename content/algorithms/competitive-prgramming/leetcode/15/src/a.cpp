#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) {
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int li = i + 1, ri = nums.size() - 1; li < ri;) {
        int sum = nums[li] + nums[ri] + nums[i];
        if (sum == 0) {
          result.push_back({nums[i], nums[li], nums[ri]});

          li++;
          ri--;

          while (li < ri && nums[li - 1] == nums[li]) {
            li++;
          }

        } else if (sum < 0) {
          li++;
        } else if (sum > 0) {
          ri--;
        }
      }
    }

    return result;
  }
};
