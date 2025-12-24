#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>>
solution(std::vector<std::vector<std::pair<int, int>>> &graph) {
  int n = graph.size() - 1;

  std::vector<int> inbound(graph.size(), 0);
  for (auto &adj_list : graph) {
    for (auto &[i, _] : adj_list) {
      inbound[i]++;
    }
  }

  std::vector<int> count(graph.size(), 0);
  std::queue<int> queue;
  std::vector<std::pair<int, int>> result;

  count[n] = 1;
  queue.push(n);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (graph[front].empty()) {
      result.push_back({front, count[front]});
    }

    for (auto &[adj, w] : graph[front]) {
      count[adj] += w * count[front];
      if (--inbound[adj] == 0) {
        queue.push(adj);
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

  int x, y, k;
  while (m--) {
    std::cin >> x >> y >> k;
    graph[x].push_back({y, k});
  }

  std::vector<std::pair<int, int>> result = solution(graph);
  std::sort(result.begin(), result.end());

  for (auto &[index, count] : result) {
    std::cout << index << ' ' << count << '\n';
  }

  return 0;
}
