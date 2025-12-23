#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using Input = std::vector<std::pair<std::pair<int, int>, int>>;

int solution(Input &input) {
  std::array<std::array<int, 3>, 3> state = {0};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      state[i][j] = 0;
    }

    state[i][i] = 1;
  }

  std::array<int, 3> result = {0};

  for (auto &[swaps, guess] : input) {
    for (int i = 0; i < 3; i++) {
      std::swap(state[i][swaps.first - 1], state[i][swaps.second - 1]);

      if (state[i][guess - 1] == 1) {
        result[i]++;
      }
    }
  }

  return *std::max_element(result.begin(), result.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n = 0;
  std::cin >> n;

  Input input(n);
  for (auto &[swaps, guess] : input) {
    std::cin >> swaps.first >> swaps.second >> guess;
  }

  std::cout << solution(input);

  return 0;
}
