#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    for (int low = 0, high = nums.size() - 1; low <= high;) {
      int mid = (low + high) / 2;

      if (target > nums[mid]) {
        if (nums[low] <= nums[high] || nums[mid] >= nums[low] ||
            target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else if (target < nums[mid]) {
        if (nums[low] <= nums[high] || nums[mid] <= nums[high] ||
            target >= nums[low]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        return mid;
      }
    }

    return -1;
  }
};
