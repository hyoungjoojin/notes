#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {

public:
  int findMin(vector<int> &nums) {
    int result = numeric_limits<int>::max();

    for (int low = 0, high = nums.size() - 1; low <= high;) {
      if (nums[low] < nums[high]) {
        result = min(result, nums[low]);
        break;
      }

      int mid = (low + high) / 2;
      if (nums[mid] > nums[low]) {
        low = mid + 1;
      } else if (nums[mid] < nums[low]) {
        high = mid - 1;
        result = min(result, nums[mid]);
      } else {
        low = mid + 1;
        result = min(result, nums[low]);
      }
    }

    return result;
  }
};
