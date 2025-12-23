#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(std::vector<std::vector<std::pair<int, int>>> &graph) {
  std::queue<int> queue;
  std::vector<int> distance(graph.size(), -1);

  queue.push(1);
  distance[1] = 0;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (auto &[adj, w] : graph[front]) {
      if (distance[adj] == -1) {
        queue.push(adj);
        distance[adj] = distance[front] + w;
      }
    }
  }

  int max = 0;
  for (int i = 1; i < graph.size(); i++) {
    if (distance[max] < distance[i]) {
      max = i;
    }
  }

  std::fill(distance.begin(), distance.end(), -1);

  queue.push(max);
  distance[max] = 0;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (auto &[adj, w] : graph[front]) {
      if (distance[adj] == -1) {
        queue.push(adj);
        distance[adj] = distance[front] + w;
      }
    }
  }

  max = 0;
  for (int i = 1; i < graph.size(); i++) {
    if (max < distance[i]) {
      max = distance[i];
    }
  }
  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

  int u, v, w;
  for (int i = 1; i < n; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  std::cout << solution(graph) << '\n';

  return 0;
}
