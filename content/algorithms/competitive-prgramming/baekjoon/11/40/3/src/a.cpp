#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void solution(std::vector<std::vector<int>> &graph) {
  std::queue<int> queue;
  std::vector<int> visited(graph.size(), 0);

  for (int i = 0; i < graph.size(); i++) {
    queue.push(i);
    visited[i] = 0;

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

    for (int j = 0; j < graph.size(); j++) {
      std::cout << visited[j] << ' ';
    }
    std::cout << '\n';

    std::fill(visited.begin(), visited.end(), 0);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n, std::vector<int>());

  int edge = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> edge;
      if (edge == 1) {
        graph[i].push_back(j);
      }
    }
  }

  solution(graph);

  return 0;
}
