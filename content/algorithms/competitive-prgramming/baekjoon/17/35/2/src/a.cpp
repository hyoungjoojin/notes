#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::pair<int, int> solution(std::vector<std::vector<int>> &graph) {
  std::vector<bool> visited(graph.size(), false);
  std::queue<int> queue;

  visited[1] = true;
  queue.push(1);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      if (!visited[adj]) {
        visited[adj] = true;
        queue.push(adj);
      }
    }
  }

  for (int i = 1; i < graph.size(); i++) {
    if (!visited[i]) {
      return {1, i};
    }
  }

  return {0, 0};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n + 1);

  int u = 0, v = 0;
  for (int i = 0; i < n - 2; i++) {
    std::cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  auto [x, y] = solution(graph);
  std::cout << x << ' ' << y << '\n';

  return 0;
}
