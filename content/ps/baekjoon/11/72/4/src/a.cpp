#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

int solution(Graph &graph) {
  int result = 0;

  std::queue<int> queue;
  std::vector<bool> visited(graph.size(), false);

  for (int i = 1; i < graph.size(); i++) {
    if (!visited[i]) {
      result++;
    }

    visited[i] = true;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int adj : graph[front]) {
        if (visited[adj]) {
          continue;
        }

        visited[adj] = true;
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

  Graph graph(n + 1, std::vector<int>());

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
