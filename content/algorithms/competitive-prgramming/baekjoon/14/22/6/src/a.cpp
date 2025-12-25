#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

int solution(int n) {
  std::vector<std::vector<int>> time(n + 1, std::vector<int>(n + 1, -1));
  std::queue<std::pair<int, int>> queue;

  time[1][0] = 0;
  queue.push({1, 0});

  while (!queue.empty()) {
    auto [count, clipboard] = queue.front();
    queue.pop();

    if (time[count][count] == -1) {
      time[count][count] = time[count][clipboard] + 1;
      queue.push({count, count});
    }

    if (clipboard != 0 && count + clipboard < time.size() &&
        time[count + clipboard][clipboard] == -1) {
      time[count + clipboard][clipboard] = time[count][clipboard] + 1;
      queue.push({count + clipboard, clipboard});
    }

    if (count > 0 && time[count - 1][clipboard] == -1) {
      time[count - 1][clipboard] = time[count][clipboard] + 1;
      queue.push({count - 1, clipboard});
    }
  }

  for (int &t : time[n]) {
    if (t == -1) {
      t = std::numeric_limits<int>::max();
    }
  }

  return *std::min_element(time[n].begin(), time[n].end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}
