class Solution {
public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    }

    int a = 1, b = 2, result;

    for (int i = 3; i <= n; i++) {
      result = a + b;
      a = b;
      b = result;
    }

    return result;
  }
};
