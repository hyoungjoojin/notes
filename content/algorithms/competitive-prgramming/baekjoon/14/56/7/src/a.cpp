#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> inbound(graph.size(), 0);
  for (auto &adj_list : graph) {
    for (int &adj : adj_list) {
      inbound[adj]++;
    }
  }

  std::queue<int> queue;
  std::vector<int> result(graph.size(), -1);

  for (int i = 1; i < graph.size(); i++) {
    if (inbound[i] == 0) {
      queue.push(i);
      result[i] = 1;
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      inbound[adj]--;

      if (result[adj] == -1 && inbound[adj] == 0) {
        queue.push(adj);
        result[adj] = result[front] + 1;
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

  std::vector<std::vector<int>> graph(n + 1);

  int u, v;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
  }

  std::vector<int> result = solution(graph);
  for (int i = 1; i <= n; i++) {
    std::cout << result[i] << ' ';
  }

  return 0;
}
