#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &scores) {
  switch (scores.size()) {
  case 1:
    return scores[0];
  case 2:
    return scores[0] + scores[1];
  case 3:
    return std::max(scores[0], scores[1]) + scores[2];
  }

  std::vector<int> result(scores.size());
  result[0] = scores[0];
  result[1] = scores[0] + scores[1];
  result[2] = std::max(scores[0], scores[1]) + scores[2];

  for (int i = 3; i < scores.size(); i++) {
    result[i] =
        scores[i] + std::max(result[i - 3] + scores[i - 1], result[i - 2]);
  }

  return result[scores.size() - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> scores(n);
  for (int &score : scores) {
    std::cin >> score;
  }

  std::cout << solution(scores) << '\n';

  return 0;
}
