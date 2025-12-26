#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &graph, int a, int b) {
  std::vector<int> distance(graph.size(), -1);
  std::queue<int> queue;

  distance[a] = 0;
  queue.push(a);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == b) {
      break;
    }

    for (int &adj : graph[front]) {
      if (distance[adj] == -1) {
        distance[adj] = distance[front] + 1;
        queue.push(adj);
      }
    }
  }

  return distance[b];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n + 1);

  int a = 0, b = 0;
  std::cin >> a >> b;

  int m = 0;
  std::cin >> m;

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << solution(graph, a, b) << '\n';

  return 0;
}
