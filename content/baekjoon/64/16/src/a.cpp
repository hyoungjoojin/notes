#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

bool solution(std::unordered_map<int, std::vector<int>> &graph) {
  if (graph.size() == 0) {
    return true;
  }

  std::unordered_map<int, int> inbound_count;
  for (auto &[i, row] : graph) {
    inbound_count[i] = 0;
    for (int &adj : row) {
      inbound_count[adj] = 0;
    }
  }

  for (auto &[i, row] : graph) {
    for (int &adj : row) {
      inbound_count[adj]++;
    }
  }

  int root = -1;
  for (auto &[i, count] : inbound_count) {
    if (count != 0) {
      continue;
    }

    if (root == -1) {
      root = i;
    } else {
      return false;
    }
  }

  if (root == -1) {
    return false;
  }

  std::queue<int> queue;
  std::unordered_map<int, int> visited;

  visited[root] = true;
  queue.push(root);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      if (!visited[adj]) {
        visited[adj] = 1;
        queue.push(adj);
      } else {
        return false;
      }
    }
  }

  for (auto &[i, v] : visited) {
    if (!v) {
      return false;
    }
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::unordered_map<int, std::vector<int>> graph;

  for (int t = 1;; t++) {
    int u = 0, v = 0;

    while (true) {
      std::cin >> u >> v;
      if (u == -1 && v == -1) {
        return 0;
      }

      if (u == 0 && v == 0) {
        break;
      }

      if (graph.find(u) == graph.end()) {
        graph[u] = std::vector<int>();
      }

      graph[u].push_back(v);
    }

    std::cout << "Case " << t << " is" << (solution(graph) ? "" : " not")
              << " a tree.\n";
    graph.clear();
  }

  return 0;
}
