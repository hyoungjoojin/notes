#include <algorithm>
#include <iostream>
#include <vector>

void solution_(std::vector<int> &slots, std::vector<bool> &visited,
               std::vector<int> &array, int start) {
  if (start == slots.size()) {
    for (int i : slots) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      visited[i] = true;
      slots[start] = array[i];
      solution_(slots, visited, array, start + 1);
      visited[i] = false;
    }
  }
}

void solution(std::vector<int> &array, int m) {
  std::sort(array.begin(), array.end());

  std::vector<int> slots(m);
  std::vector<bool> visited(array.size(), false);
  solution_(slots, visited, array, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  solution(array, m);

  return 0;
}
