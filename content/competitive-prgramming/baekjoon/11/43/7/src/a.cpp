#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void solution(std::vector<std::vector<int>> &tree, int m) {
  std::queue<int> queue;
  std::vector<int> parent(tree.size(), -1), depth(tree.size(), -1);

  queue.push(1);
  parent[1] = -1;
  depth[1] = 1;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : tree[front]) {
      if (depth[adj] == -1) {
        queue.push(adj);
        parent[adj] = front;
        depth[adj] = depth[front] + 1;
      }
    }
  }

  int u = 0, v = 0;
  while (m--) {
    std::cin >> u >> v;

    if (depth[u] != depth[v]) {
      if (depth[u] > depth[v]) {
        std::swap(u, v);
      }

      for (int t = depth[v] - depth[u]; t > 0; t--) {
        v = parent[v];
      }
    }

    while (u != v) {
      u = parent[u];
      v = parent[v];
    }

    std::cout << u << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> tree(n + 1);

  int u = 0, v = 0;
  for (int i = 1; i < n; i++) {
    std::cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int m = 0;
  std::cin >> m;

  solution(tree, m);

  return 0;
}
