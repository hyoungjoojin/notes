#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> bacon(graph.size(), 0);

  std::vector<int> distance(graph.size(), -1);
  std::queue<int> queue;

  for (int i = 1; i < graph.size(); i++) {
    distance[i] = 0;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &adj : graph[front]) {
        if (distance[adj] == -1) {
          distance[adj] = distance[front] + 1;
          queue.push(adj);
        }
      }
    }

    for (int j = 1; j < graph.size(); j++) {
      bacon[j] += distance[j];
    }

    std::fill(distance.begin(), distance.end(), -1);
  }

  int min = 1;
  for (int i = 1; i < graph.size(); i++) {
    if (bacon[min] > bacon[i]) {
      min = i;
    }
  }

  return min;
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
