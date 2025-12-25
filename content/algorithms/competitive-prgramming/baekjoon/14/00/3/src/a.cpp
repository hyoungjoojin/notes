#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &array) {
  std::vector<int> tails, tails_index, predecessor(array.size(), -1);

  int end = 0;
  for (int i = 0; i < array.size(); i++) {
    int l =
        std::lower_bound(tails.begin(), tails.end(), array[i]) - tails.begin();

    if (l == tails.size()) {
      tails.push_back(array[i]);
      tails_index.push_back(i);
      end = i;
    } else {
      tails[l] = array[i];
      tails_index[l] = i;
    }

    predecessor[i] = (l == 0 ? i : tails_index[l - 1]);
  }

  std::vector<int> result;

  int current = end;
  while (current != predecessor[current]) {
    result.push_back(array[current]);
    current = predecessor[current];
  }
  result.push_back(array[current]);

  std::reverse(result.begin(), result.end());
  return result;
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

  std::vector<int> result = solution(array);

  std::cout << result.size() << '\n';
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
