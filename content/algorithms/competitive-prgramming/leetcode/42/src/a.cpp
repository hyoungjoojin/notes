#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int result = 0;

    int lmax = 0, rmax = 0;
    for (int li = 0, ri = height.size() - 1; li <= ri;) {
      if (lmax <= rmax) {
        result += max(lmax - height[li], 0);
        lmax = max(lmax, height[li]);
        li++;
      } else {
        result += max(rmax - height[ri], 0);
        rmax = max(rmax, height[ri]);
        ri--;
      }
    }

    return result;
  }
};
