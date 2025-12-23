#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int solution(std::string &input) {
  std::vector<int> energy(input.size(), 0);

  energy[0] = 0;
  for (int cur = 1; cur < input.size(); cur++) {
    int min = std::numeric_limits<int>::max();

    for (int prev = 0; prev < cur; prev++) {
      if (energy[prev] == -1) {
        continue;
      }

      if ((input[cur] == 'B' && input[prev] == 'J') ||
          (input[cur] == 'O' && input[prev] == 'B') ||
          (input[cur] == 'J' && input[prev] == 'O')) {
        min = std::min(min, energy[prev] + (cur - prev) * (cur - prev));
      }

      energy[cur] = (min == std::numeric_limits<int>::max() ? -1 : min);
    }
  }

  return energy[input.size() - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::string input;
  std::cin >> input;

  std::cout << solution(input) << '\n';

  return 0;
}
