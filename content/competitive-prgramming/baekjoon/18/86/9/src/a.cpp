#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int solution(std::vector<std::vector<int>> &arrays) {
  int n = arrays[0].size();

  std::vector<int> sorted_array(n);
  std::unordered_map<int, int> index;

  for (auto &array : arrays) {
    for (int i = 0; i < n; i++) {
      sorted_array[i] = array[i];
    }

    std::sort(sorted_array.begin(), sorted_array.end());
    for (int i = 0; i < n; i++) {
      index[sorted_array[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      array[i] = index[array[i]];
    }
  }

  int count = 0;
  for (int i = 0; i < arrays.size(); i++) {
    for (int j = i + 1; j < arrays.size(); j++) {
      bool equals = true;

      for (int k = 0; k < n; k++) {
        if (arrays[i][k] != arrays[j][k]) {
          equals = false;
          break;
        }
      }

      if (equals) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<int>> arrays(m, std::vector<int>(n));

  for (auto &array : arrays) {
    for (int &i : array) {
      std::cin >> i;
    }
  }

  std::cout << solution(arrays) << '\n';

  return 0;
}
