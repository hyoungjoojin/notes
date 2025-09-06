#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

int max(std::array<int, 3> &front, std::array<int, 3> &back) {
  int result = front[0] + back[1];
  result = std::max(result, front[0] + back[2]);
  result = std::max(result, front[1] + back[0]);
  result = std::max(result, front[1] + back[2]);
  result = std::max(result, front[2] + back[0]);
  result = std::max(result, front[2] + back[1]);
  return result;
}

int solution(std::vector<char> &gestures) {
  std::vector<std::array<int, 3>> pcount(gestures.size() + 1);

  pcount[0] = {0};
  for (int i = 1; i <= gestures.size(); i++) {
    pcount[i][0] = pcount[i - 1][0] + (gestures[i - 1] == 'H' ? 1 : 0);
    pcount[i][1] = pcount[i - 1][1] + (gestures[i - 1] == 'P' ? 1 : 0);
    pcount[i][2] = pcount[i - 1][2] + (gestures[i - 1] == 'S' ? 1 : 0);
  }

  int result = 0;

  std::array<int, 3> front, back;
  for (int i = 1; i <= gestures.size(); i++) {
    for (int k = 0; k < 3; k++) {
      front[k] = pcount[i][k] - pcount[0][k];
      back[k] = pcount[gestures.size()][k] - pcount[i - 1][k];
    }

    result = std::max(result, max(front, back));
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n = 0;
  std::cin >> n;

  std::vector<char> input(n);
  for (char &ch : input) {
    std::cin >> ch;
  }

  std::cout << solution(input) << '\n';

  return 0;
}
