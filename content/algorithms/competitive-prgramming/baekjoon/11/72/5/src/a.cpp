#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> result(graph.size() + 1, -1);

  std::queue<int> queue;

  result[1] = 1;
  queue.push(1);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int adj : graph[front]) {
      if (result[adj] != -1) {
        continue;
      }

      result[adj] = front;
      queue.push(adj);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());

  int u, v;
  while (n--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector<int> result = solution(graph);
  for (int i = 2; i < result.size() - 1; i++) {
    std::cout << result[i] << '\n';
  }

  return 0;
}
