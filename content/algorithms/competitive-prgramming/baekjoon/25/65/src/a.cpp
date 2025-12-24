#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

int solution(std::vector<std::pair<int, int>> &lines) {
  std::sort(lines.begin(), lines.end(), std::less<>());

  std::vector<int> array(lines.size());
  for (int i = 0; i < lines.size(); i++) {
    array[i] = lines[i].second;
  }

  std::vector<int> tails;
  for (int i : array) {
    auto lower_bound = std::lower_bound(tails.begin(), tails.end(), i);
    if (lower_bound == tails.end()) {
      tails.push_back(i);
    } else {
      *lower_bound = i;
    }
  }

  return lines.size() - tails.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> lines(n);
  for (auto &[left, right] : lines) {
    std::cin >> left >> right;
  }

  std::cout << solution(lines) << '\n';

  return 0;
}
