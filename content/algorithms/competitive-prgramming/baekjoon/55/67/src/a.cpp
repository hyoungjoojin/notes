#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> distance(graph.size(), -1);
  std::queue<int> queue;

  distance[1] = 0;
  queue.push(1);

  int count = 0;
  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (distance[front] > 2) {
      continue;
    } else {
      count++;
    }

    for (int &adj : graph[front]) {
      if (distance[adj] == -1) {
        distance[adj] = distance[front] + 1;
        queue.push(adj);
      }
    }
  }

  return count - 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());

  int u, v;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
