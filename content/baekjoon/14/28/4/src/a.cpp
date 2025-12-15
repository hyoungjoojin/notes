#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

int solution(int s, int t,
             std::vector<std::vector<std::pair<int, int>>> &graph) {
  std::vector<int> distance(graph.size(), std::numeric_limits<int>::max());
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  distance[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [d_top, top] = pq.top();
    pq.pop();

    if (distance[top] < d_top) {
      continue;
    }

    for (auto &[adj, w_adj] : graph[top]) {
      if (distance[top] + w_adj < distance[adj]) {
        distance[adj] = distance[top] + w_adj;
        pq.push({distance[adj], adj});
      }
    }
  }

  return distance[t];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

  int u, v, w;
  while (m--) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  int s = 0, t = 0;
  std::cin >> s >> t;

  std::cout << solution(s, t, graph) << '\n';

  return 0;
}
