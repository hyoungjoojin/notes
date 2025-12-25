#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int result = 0;

    for (int li = 0, ri = height.size() - 1; li < ri;) {
      result = max(result, (ri - li) * min(height[li], height[ri]));

      if (height[li] < height[ri]) {
        li++;
      } else {
        ri--;
      }
    }

    return result;
  }
};
