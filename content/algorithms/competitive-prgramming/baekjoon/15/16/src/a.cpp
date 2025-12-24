#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<std::vector<int>> &graph,
                          std::vector<int> &time) {
  std::vector<int> inbound(time.size(), 0);
  for (auto &adj_list : graph) {
    for (int &adj : adj_list) {
      inbound[adj]++;
    }
  }

  std::vector<int> result(time.size(), -1);
  std::queue<int> queue;

  for (int i = 1; i < time.size(); i++) {
    if (inbound[i] == 0) {
      result[i] = time[i];
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      inbound[adj]--;

      result[adj] = std::max(result[adj], result[front]);

      if (inbound[adj] == 0) {
        result[adj] += time[adj];
        queue.push(adj);
      }
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

  std::vector<std::vector<int>> graph(n + 1);
  std::vector<int> time(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    std::cin >> time[i];

    int previous = 0;
    while (true) {
      std::cin >> previous;

      if (previous == -1) {
        break;
      }

      graph[previous].push_back(i);
    }
  }

  std::vector<int> result = solution(graph, time);
  for (int i = 1; i < result.size(); i++) {
    std::cout << result[i] << '\n';
  }

  return 0;
}
