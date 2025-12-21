#include <algorithm>
#include <cassert>
#include <vector>

/**
 * Find the longest increasing subsequence in an array. If there are multiple,
 * any one of the longest will be returned.
 *
 * @param array The input array of integers.
 * @return The longest increasing subsequence.
 */
std::vector<int> solution(const std::vector<int> &array) {
  // Since we need to index into the array for reconstruction, we handle the
  // empty case separately.
  if (array.empty()) {
    return {};
  }

  // tails[i] is the smallest integer that ends an increasing subsequence of
  // length i. tails_index[i] is the index of tails[i] in the original array. We
  // maintain this to reconstruct the sequence later. parents[i] will be the
  // predecessor of array[i] in the longest increasing subsequence that ends at
  // index i.
  std::vector<int> tails, tails_index, parents(array.size(), -1);

  // We have to search for the index that has the maximum length subsequence,
  // but since any one of the sequences is acceptable, we can just track the
  // last index that was added to tails.
  int best = 0;

  for (int i = 0; i < array.size(); i++) {
    // We first find the length of the longest subsequence that can be extended
    // with array[i].
    int l =
        std::lower_bound(tails.begin(), tails.end(), array[i]) - tails.begin();

    if (l == tails.size()) {
      // If the length is equal to the size of tails, it means we have found a
      // new longest subsequence. We append the new value to tails and
      // tails_index, and update best.
      tails.push_back(array[i]);
      tails_index.push_back(i);
      best = i;
    } else {
      // Otherwise, we update the existing value at index l.
      tails[l] = array[i];
      tails_index[l] = i;
    }

    // The parent at index i will be the index of the last element of the
    // subsequence of length l.
    parents[i] = (l == 0) ? i : tails_index[l - 1];
  }

  std::vector<int> result;

  // We reconstruct the longest increasing subsequence by following the parents
  // from the best index. We repeat this until we reach an index that is its own
  // parent.
  int current = best;
  while (parents[current] != current) {
    result.push_back(array[current]);
    current = parents[current];
  }
  result.push_back(array[current]);

  // Since the results were added in reverse order, we need to reverse them
  // before returning.
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::vector<int> input = {1, 4, 3, 6, 3, 7, 3, 2};

  std::vector<std::vector<int>> candidates = {{1, 4, 6, 7}, {1, 3, 6, 7}};
  std::vector<int> actual = solution(input);

  bool matched = false;

  for (std::vector<int> &candidate : candidates) {
    if (candidate.size() != actual.size()) {
      continue;
    }

    for (size_t i = 0; i < candidate.size(); i++) {
      if (candidate[i] != actual[i]) {
        break;
      }

      if (i == candidate.size() - 1) {
        matched = true;
      }
    }
  }

  assert(matched);

  return 0;
}
