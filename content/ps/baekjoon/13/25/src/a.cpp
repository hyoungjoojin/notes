#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> count(graph.size(), 0);

  std::queue<int> queue;
  std::vector<int> visited(graph.size(), 0);

  for (int i = 1; i < graph.size(); i++) {
    queue.push(i);
    visited[i] = 1;

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &adj : graph[front]) {
        if (visited[adj] == 0) {
          queue.push(adj);
          visited[adj] = 1;
        }
      }
    }

    count[i] = std::count(visited.begin(), visited.end(), 1);
    std::fill(visited.begin(), visited.end(), 0);
  }

  int max = *std::max_element(count.begin(), count.end());

  std::vector<int> result;
  for (int i = 1; i < count.size(); i++) {
    if (count[i] == max) {
      result.push_back(i);
    }
  }

  std::sort(result.begin(), result.end());
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
    graph[v].push_back(u);
  }

  std::vector<int> result = solution(graph);
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
