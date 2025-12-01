#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &array) {
  std::vector<int> tails;
  for (int &i : array) {
    auto lower_bound = std::lower_bound(tails.begin(), tails.end(), i);

    if (lower_bound == tails.end()) {
      tails.push_back(i);
    } else {
      *lower_bound = i;
    }
  }

  return array.size() - tails.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
