#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using PLI = std::pair<long long, int>;
using Graph = std::vector<std::vector<PLI>>;

const long long INF = std::numeric_limits<long long>::max();

long long solution(Graph &graph, int start, int end) {
  std::vector<long long> distance(graph.size(), INF);
  std::vector<int> parent(graph.size());
  std::priority_queue<PLI, std::vector<PLI>, std::greater<PLI>> pq;

  distance[start] = 0;
  parent[start] = start;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (distance[v] != d_v) {
      continue;
    }

    for (auto &[w, adj] : graph[v]) {
      if (distance[adj] > d_v + w) {
        distance[adj] = d_v + w;
        parent[adj] = v;
        pq.push({distance[adj], adj});
      }
    }
  }

  return distance[end];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  Graph graph(n + 1);

  int a, b, w;
  while (m--) {
    std::cin >> a >> b >> w;
    graph[a].push_back({w, b});
  }

  int start = 0, end = 0;
  std::cin >> start >> end;

  std::cout << solution(graph, start, end) << '\n';

  return 0;
}
