#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<std::pair<int, int>>> &graph) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;
  std::vector<int> visited(graph.size());

  int result = 0;

  pq.push({0, 1});

  while (!pq.empty()) {
    auto [w, v] = pq.top();
    pq.pop();

    if (visited[v]) {
      continue;
    }

    result += w;
    visited[v] = true;

    for (auto &[adj, adj_w] : graph[v]) {
      if (!visited[adj]) {
        pq.push({adj_w, adj});
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

  int u = 0, v = 0, w = 0;
  while (m--) {
    std::cin >> u >> v >> w;

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
