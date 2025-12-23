#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &lengths, int n) {
  long result = 0;

  for (long li = 1, ri = *std::max_element(lengths.begin(), lengths.end());
       li <= ri;) {
    long mid = (li + ri) / 2;

    long long sum = 0;
    for (int i : lengths) {
      sum += (long)(i / mid);
    }

    if (sum >= n) {
      result = std::max(result, mid);
      li = mid + 1;
    } else {
      ri = mid - 1;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k = 0, n = 0;
  std::cin >> k >> n;

  std::vector<int> lengths(k);
  for (int &i : lengths) {
    std::cin >> i;
  }

  std::cout << solution(lengths, n) << '\n';

  return 0;
}
