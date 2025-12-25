#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &grid) {
  int n = grid.size();

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (int i = 0; i < n; i++) {
    min_heap.push(grid[n - 1][i]);
  }

  std::vector<bool> finished(grid.size(), false);
  for (int level = 2; level <= n; level++) {
    bool all_finished = true;
    for (int i = 0; i < n; i++) {
      if (finished[i]) {
        continue;
      }

      if (min_heap.top() > grid[n - level][i]) {
        finished[i] = true;
      } else {
        min_heap.push(grid[n - level][i]);
        min_heap.pop();
        all_finished = false;
      }
    }

    if (all_finished) {
      break;
    }
  }

  return min_heap.top();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> grid(n, std::vector<int>(n));
  for (std::vector<int> &row : grid) {
    for (int &x : row) {
      std::cin >> x;
    }
  }

  std::cout << solution(grid) << '\n';

  return 0;
}
