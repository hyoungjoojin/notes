#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &order, int v,
         int &current) {
  order[v] = current++;

  for (int &i : graph[v]) {
    if (order[i] == 0) {
      dfs(graph, order, i, current);
    }
  }
}

std::vector<int> solution(std::vector<std::vector<int>> &graph, int start) {
  for (auto &adj_list : graph) {
    std::sort(adj_list.begin(), adj_list.end(), std::greater<>());
  }

  std::vector<int> order(graph.size(), 0);
  int current = 1;

  dfs(graph, order, start, current);

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
