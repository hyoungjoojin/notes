#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> result;

  std::vector<bool> visited(graph.size(), false);
  std::queue<int> queue;

  for (int i = 1; i < graph.size(); i++) {
    if (visited[i]) {
      continue;
    }

    std::vector<int> nodes;
    visited[i] = true;
    nodes.push_back(i);
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &i : graph[front]) {
        if (!visited[i]) {
          visited[i] = true;
          nodes.push_back(i);
          queue.push(i);
        }
      }
    }

    int min_index = i, min_distance = std::numeric_limits<int>::max();

    std::vector<int> distance(graph.size(), -1);
    for (int i : nodes) {
      int max_distance = 0;

      distance[i] = 0;
      queue.push(i);

      while (!queue.empty()) {
        int front = queue.front();
        queue.pop();

        for (int &adj : graph[front]) {
          if (distance[adj] == -1) {
            distance[adj] = distance[front] + 1;
            if (distance[adj] > max_distance) {
              max_distance = distance[adj];
            }
            queue.push(adj);
          }
        }
      }

      if (max_distance < min_distance) {
        min_index = i;
        min_distance = max_distance;
      }

      std::fill(distance.begin(), distance.end(), -1);
    }

    result.push_back(min_index);
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

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector<int> result = solution(graph);
  std::sort(result.begin(), result.end());

  std::cout << result.size() << '\n';
  for (int &i : result) {
    std::cout << i << '\n';
  }

  return 0;
}
