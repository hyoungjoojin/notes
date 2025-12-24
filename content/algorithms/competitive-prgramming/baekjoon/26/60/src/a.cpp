#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::pair<std::vector<int>, int>
solution(std::vector<std::vector<int>> &graph) {
  std::vector<int> distance(graph.size()), max_distance(graph.size(), 0);
  std::queue<int> queue;

  for (int i = 1; i < graph.size(); i++) {
    std::fill(distance.begin(), distance.end(), -1);

    distance[i] = 0;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &adj : graph[front]) {
        if (distance[adj] == -1) {
          distance[adj] = distance[front] + 1;
          queue.push(adj);
          max_distance[adj] = std::max(max_distance[adj], distance[adj]);
        }
      }
    }
  }

  int score = *std::min_element(max_distance.begin() + 1, max_distance.end());

  std::vector<int> result;
  for (int i = 1; i < graph.size(); i++) {
    if (max_distance[i] == score) {
      result.push_back(i);
    }
  }

  return {result, score};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> graph(n + 1);

  int u = 0, v = 0;
  while (std::cin >> u >> v) {
    if (u == -1 && v == -1) {
      break;
    }

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  auto [result, score] = solution(graph);
  std::sort(result.begin(), result.end());

  std::cout << score << ' ' << result.size() << '\n';
  for (int &i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
