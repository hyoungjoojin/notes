#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using PII = std::pair<int, int>;
using Graph = std::vector<std::vector<PII>>;

const int INF = std::numeric_limits<int>::max();

std::vector<int> solution(Graph &graph, int start) {
  std::vector<int> distance(graph.size(), INF);
  std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;

  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (d_v != distance[v]) {
      continue;
    }

    for (auto &[w, adj] : graph[v]) {
      if (distance[adj] > d_v + w) {
        distance[adj] = d_v + w;
        pq.push({distance[adj], adj});
      }
    }
  }

  return distance;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int v = 0, e = 0, start = 0;
  std::cin >> v >> e >> start;

  Graph graph(v + 1);

  int a, b, w;
  while (e--) {
    std::cin >> a >> b >> w;
    graph[a].push_back({w, b});
  }

  std::vector<int> distance = solution(graph, start);

  for (int i = 1; i < distance.size(); i++) {
    if (distance[i] == INF) {
      std::cout << "INF\n";
    } else {
      std::cout << distance[i] << '\n';
    }
  }

  return 0;
}
