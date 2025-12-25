#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> visited(graph.size(), 0);
  std::queue<int> queue;

  int result = 0, num_components = 0;

  for (int i = 1; i < graph.size(); i++) {
    if (visited[i]) {
      continue;
    }

    int num_nodes = 0, num_edges = 0;
    num_components++;

    visited[i] = 1;
    queue.push(i);
    num_nodes++;
    num_edges += graph[i].size();

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &adj : graph[front]) {
        if (!visited[adj]) {
          visited[adj] = 1;
          queue.push(adj);
          num_nodes++;
          num_edges += graph[adj].size();
        }
      }
    }

    result += (num_edges / 2 - (num_nodes - 1));
  }

  result += (num_components - 1);
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
