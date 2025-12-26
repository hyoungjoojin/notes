#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

long long solution(std::vector<std::vector<int>> &graph) {
  std::vector<bool> visited(graph.size(), false);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  long long mst = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (visited[v]) {
      continue;
    }

    mst += d_v;
    visited[v] = true;

    for (int i = 0; i < graph.size(); i++) {
      if (!visited[i]) {
        pq.push({graph[v][i], i});
      }
    }
  }

  return mst;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
  for (auto &row : graph) {
    for (int &i : row) {
      std::cin >> i;
    }
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
