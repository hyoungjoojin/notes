#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &order, int v,
         int &current_order) {
  order[v] = current_order++;

  for (int &adj : graph[v]) {
    if (order[adj] == -1) {
      dfs(graph, order, adj, current_order);
    }
  }
}

std::vector<int> solution(std::vector<std::vector<int>> &graph, int start) {
  for (auto &adj_list : graph) {
    std::sort(adj_list.begin(), adj_list.end());
  }

  std::vector<int> order(graph.size(), -1);

  int current_order = 1;
  dfs(graph, order, start, current_order);

  for (int &o : order) {
    if (o == -1) {
      o = 0;
    }
  }

  return order;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0, r = 0;
  std::cin >> n >> m >> r;

  std::vector<std::vector<int>> graph(n + 1);

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector<int> result = solution(graph, r);
  for (int i = 1; i < result.size(); i++) {
    std::cout << result[i] << '\n';
  }

  return 0;
}
