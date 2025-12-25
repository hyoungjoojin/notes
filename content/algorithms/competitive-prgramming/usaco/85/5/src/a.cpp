#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <utility>

using Input = std::array<std::pair<int, int>, 3>;

std::array<int, 3> solution(Input &input) {
  std::array<int, 3> result;
  for (int i = 0; i < 3; i++) {
    result[i] = input[i].second;
  }

  int iter = 100, turn = 0, next = 0;
  while (iter--) {
    next = (turn + 1) % 3;

    int poured = std::min(input[next].first - result[next], result[turn]);
    result[next] += poured;
    result[turn] -= poured;

    turn = next;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  Input input;
  for (int i = 0; i < 3; i++) {
    std::cin >> input[i].first >> input[i].second;
  }

  std::array<int, 3> result = solution(input);
  for (int i : result) {
    std::cout << i << '\n';
  }

  return 0;
}
