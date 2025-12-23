#include <algorithm>
#include <cassert>
#include <vector>

/**
 * Find the length of the longest increasing subsequence in an array.
 *
 * @param array The input array of integers.
 * @return The length of the longest increasing subsequence in the array.
 */
int solution(const std::vector<int> &array) {
  // tails[i] is the smallest integer that ends an increasing subsequence of
  // length i.
  std::vector<int> tails;

  for (int i : array) {
    // For each iteration, we search for the smallest value in tails that is
    // greater or equal than i. We will replace this value with i in the next
    // steps.
    auto l = std::lower_bound(tails.begin(), tails.end(), i);

    if (l == tails.end()) {
      // The first case that can happen is when i is the largest value of tails.
      // In this case, we can insert the value directly into tails and the
      // longest increasing subsequence will be the one ending in the newly
      // inserted value.
      tails.push_back(i);
    } else {
      // In the second case, we will replace the iterator with i. This does not
      // affect the length of the longest increasing subsequence since the
      // previous longest increasing subsequence won't be affected (the last
      // value of tails still indicates the subsequence ending in the last value
      // of tails). If future items extend tails, then that subsequence will
      // include the newly inserted i.
      *l = i;
    }
  }

  // We only need the length of the longest increasing subsequence, so we return
  // the size of tails.
  return tails.size();
}

int main() {
  std::vector<int> input = {1, 4, 3, 6, 3, 7, 3, 2};

  int expected = 4, actual = solution(input);
  assert(expected == actual);

  return 0;
}
