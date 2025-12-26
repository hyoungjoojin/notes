#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> solution(std::vector<std::pair<int, int>> &input) {
  std::sort(input.begin(), input.end(),
            [](std::pair<int, int> &p1, std::pair<int, int> &p2) {
              return p1.second < p2.second;
            });

  std::vector<int> tails, tails_index, predecessor(input.size());

  int max = 0;

  for (int i = 0; i < input.size(); i++) {
    int l = std::lower_bound(tails.begin(), tails.end(), input[i].first) -
            tails.begin();

    if (l == tails.size()) {
      tails.push_back(input[i].first);
      tails_index.push_back(i);
      max = i;
    } else {
      tails[l] = input[i].first;
      tails_index[l] = i;
    }

    predecessor[i] = (l == 0 ? i : tails_index[l - 1]);
  }

  std::vector<int> lis;
  int current = max;

  while (current != predecessor[current]) {
    lis.push_back(input[current].first);
    current = predecessor[current];
  }
  lis.push_back(input[current].first);

  std::reverse(lis.begin(), lis.end());

  std::vector<int> result;
  for (int i = 0, j = 0; i < input.size(); i++) {
    if (j == lis.size()) {
      result.push_back(input[i].first);
      continue;
    }

    if (input[i].first != lis[j]) {
      result.push_back(input[i].first);
    } else {
      j++;
    }
  }

  std::sort(result.begin(), result.end());
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> input(n);
  for (auto &[a, b] : input) {
    std::cin >> a >> b;
  }

  std::vector<int> result = solution(input);

  std::cout << result.size() << '\n';
  for (int &i : result) {
    std::cout << i << '\n';
  }

  return 0;
}
