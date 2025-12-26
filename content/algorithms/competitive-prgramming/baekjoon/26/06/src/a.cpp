#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &graph) {
  std::vector<bool> visited(graph.size(), false);
  std::queue<int> queue;

  int count = 0;
  visited[1] = true;
  queue.push(1);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      if (!visited[adj]) {
        count++;
        visited[adj] = true;
        queue.push(adj);
      }
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n + 1);

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
