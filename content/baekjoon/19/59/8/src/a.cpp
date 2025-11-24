#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::pair<int, int>> &time) {
  std::sort(time.begin(), time.end());

  std::priority_queue<int, std::vector<int>, std::greater<>> pq;

  int result = 0;
  for (auto &[start, end] : time) {
    while (!pq.empty() && pq.top() <= start) {
      pq.pop();
    }

    pq.push(end);
    result = std::max(result, static_cast<int>(pq.size()));
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> time(n);
  for (auto &[start, end] : time) {
    std::cin >> start >> end;
  }

  std::cout << solution(time) << '\n';

  return 0;
}
