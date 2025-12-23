#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result(2);

    for (int li = 0, ri = numbers.size() - 1; li < ri;) {
      int sum = numbers[li] + numbers[ri];

      if (sum == target) {
        result[0] = li + 1;
        result[1] = ri + 1;
        break;
      } else if (sum < target) {
        li++;
      } else if (sum > target) {
        ri--;
      }
    }

    return result;
  }
};
