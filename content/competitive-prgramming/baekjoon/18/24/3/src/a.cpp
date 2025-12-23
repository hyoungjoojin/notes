#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

bool solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> distance(graph.size(), -1);
  std::queue<int> queue;

  for (int i = 1; i < graph.size(); i++) {
    int max_distance = 0, count = 1;
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
          count++;
        }
      }
    }

    if (count != graph.size() - 1 || max_distance > 6) {
      return false;
    }

    std::fill(distance.begin(), distance.end(), -1);
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<std::vector<int>> graph(n + 1);

  int u = 0, v = 0;
  while (k--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << (solution(graph) ? "Small World!\n" : "Big World!\n");

  return 0;
}
