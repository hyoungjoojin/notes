#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<std::vector<int>> &tree, int u, int v) {
  std::vector<int> inbound(tree.size(), 0);
  for (auto &adj_list : tree) {
    for (int &adj : adj_list) {
      inbound[adj]++;
    }
  }

  int root = -1;
  for (int i = 1; i < tree.size(); i++) {
    if (inbound[i] == 0) {
      root = i;
      break;
    }
  }

  std::vector<int> visited(tree.size(), 0);
  std::queue<int> queue;
  std::vector<int> depth(tree.size(), 0);
  std::vector<int> parent(tree.size(), -1);

  visited[root] = 1;
  queue.push(root);
  depth[root] = 0;
  parent[root] = -1;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : tree[front]) {
      if (!visited[adj]) {
        visited[adj] = 1;
        queue.push(adj);
        depth[adj] = depth[front] + 1;
        parent[adj] = front;
      }
    }
  }

  while (depth[u] != depth[v]) {
    if (depth[u] > depth[v]) {
      u = parent[u];
    } else {
      v = parent[v];
    }
  }

  while (u != v) {
    u = parent[u];
    v = parent[v];
  }

  return u;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0, u = 0, v = 0;
  std::vector<std::vector<int>> graph;

  while (t--) {
    std::cin >> n;
    graph.resize(n + 1);

    for (int i = 1; i < n; i++) {
      std::cin >> u >> v;
      graph[u].push_back(v);
    }

    std::cin >> u >> v;
    std::cout << solution(graph, u, v) << '\n';
    graph.clear();
  }

  return 0;
}
