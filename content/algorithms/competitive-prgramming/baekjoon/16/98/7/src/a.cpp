#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int solution_(std::vector<std::pair<int, int>> &eggs, int index) {
  if (index == eggs.size()) {
    int count = 0;
    for (auto &[s, _] : eggs) {
      if (s <= 0) {
        count++;
      }
    }

    return count;
  }

  if (eggs[index].first <= 0) {
    return solution_(eggs, index + 1);
  }

  int result = 0, cracked = 0;

  for (int i = 0; i < eggs.size(); i++) {
    if (eggs[i].first <= 0 || i == index) {
      continue;
    }

    cracked++;

    eggs[i].first -= eggs[index].second;
    eggs[index].first -= eggs[i].second;

    result = std::max(result, solution_(eggs, index + 1));

    eggs[i].first += eggs[index].second;
    eggs[index].first += eggs[i].second;
  }

  if (cracked == 0) {
    result = std::max(result, solution_(eggs, index + 1));
  }

  return result;
}

int solution(std::vector<std::pair<int, int>> &eggs) {
  return solution_(eggs, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> input(n);
  for (auto &[s, w] : input) {
    std::cin >> s >> w;
  }

  std::cout << solution(input) << '\n';

  return 0;
}
