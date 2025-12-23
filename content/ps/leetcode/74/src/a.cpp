#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row;
    for (int low = 0, high = matrix.size() - 1; low <= high;) {
      int mid = (low + high) / 2;

      if (target > matrix[mid][0]) {
        row = mid;
        low = mid + 1;
      } else if (target < matrix[mid][0]) {
        high = mid - 1;
      } else {
        return true;
      }
    }

    for (int left = 0, right = matrix[0].size() - 1; left <= right;) {
      int mid = (left + right) / 2;

      if (target < matrix[row][mid]) {
        right = mid - 1;
      } else if (target > matrix[row][mid]) {
        left = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
