#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using PII = std::pair<int, int>;

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>> &graph,
                          int start) {
  std::priority_queue<PII, std::vector<PII>, std::greater<>> pq;
  std::vector<int> distance(graph.size(), std::numeric_limits<int>::max());

  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d_u, u] = pq.top();
    pq.pop();

    if (d_u > distance[u]) {
      continue;
    }

    for (auto &[adj, d_adj] : graph[u]) {
      if (distance[u] + d_adj < distance[adj]) {
        distance[adj] = distance[u] + d_adj;
        pq.push({distance[adj], adj});
      }
    }
  }

  return distance;
}

std::vector<int> solution(std::vector<std::vector<std::pair<int, int>>> &graph,
                          int start, int u, int v,
                          std::vector<int> &candidates) {
  std::vector<int> from_start = dijkstra(graph, start),
                   from_u = dijkstra(graph, u), from_v = dijkstra(graph, v);

  int d = 0;
  for (auto &[adj, d_adj] : graph[u]) {
    if (adj == v) {
      d = d_adj;
      break;
    }
  }

  std::vector<int> result;
  for (int &candidate : candidates) {
    int u_to_v = from_start[u] + d + from_v[candidate],
        v_to_u = from_start[v] + d + from_u[candidate];

    if (from_start[candidate] == u_to_v || from_start[candidate] == v_to_u) {
      result.push_back(candidate);
    }
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::vector<std::vector<std::pair<int, int>>> graph;
  std::vector<int> candidates;

  int n = 0, m = 0, c = 0, s = 0, g = 0, h = 0;
  while (t--) {
    std::cin >> n >> m >> c;
    graph.resize(n + 1);
    candidates.resize(c);

    std::cin >> s >> g >> h;

    int u = 0, v = 0, d = 0;
    while (m--) {
      std::cin >> u >> v >> d;
      graph[u].push_back({v, d});
      graph[v].push_back({u, d});
    }

    for (int &i : candidates) {
      std::cin >> i;
    }

    std::vector<int> result = solution(graph, s, g, h, candidates);
    std::sort(result.begin(), result.end());
    for (int &i : result) {
      std::cout << i << ' ';
    }
    std::cout << '\n';

    graph.clear();
    candidates.clear();
  }

  return 0;
}
