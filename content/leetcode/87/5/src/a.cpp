#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {

public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int result = numeric_limits<int>::max();

    for (int low = 1, high = *max_element(piles.begin(), piles.end());
         low <= high;) {
      int mid = (low + high) / 2;

      long count = 0;
      for (int p : piles) {
        count += (p / mid + (p % mid == 0 ? 0 : 1));
      }

      if (count > h) {
        low = mid + 1;
      } else if (count <= h) {
        result = min(result, mid);
        high = mid - 1;
      }
    }

    return result;
  }
};
