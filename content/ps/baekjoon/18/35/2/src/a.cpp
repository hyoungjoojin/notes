#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph, int start,
                          int k) {
  std::vector<int> distance(graph.size(), -1);
  std::queue<int> queue;

  distance[start] = 0;
  queue.push(start);

  std::vector<int> result;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (distance[front] == k) {
      result.push_back(front);
      continue;
    }

    for (int &adj : graph[front]) {
      if (distance[adj] == -1) {
        distance[adj] = distance[front] + 1;
        queue.push(adj);
      }
    }
  }

  std::sort(result.begin(), result.end());
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0, k = 0, x = 0;
  std::cin >> n >> m >> k >> x;

  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;
    graph[u].push_back(v);
  }

  std::vector<int> result = solution(graph, x, k);
  if (result.empty()) {
    std::cout << "-1\n";
  } else {
    for (int &x : result) {
      std::cout << x << '\n';
    }
  }

  return 0;
}
