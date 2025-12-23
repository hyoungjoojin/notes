#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void solution(std::vector<std::vector<int>> &tree, int m) {
  std::queue<int> queue;
  std::vector<int> depth(tree.size(), -1);

  std::vector<std::vector<int>> parent;
  parent.push_back(std::vector<int>(tree.size(), -1));

  queue.push(1);
  depth[1] = 0;
  parent[0][1] = -1;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : tree[front]) {
      if (depth[adj] == -1) {
        queue.push(adj);
        depth[adj] = depth[front] + 1;
        parent[0][adj] = front;
      }
    }
  }

  int max_depth = *std::max_element(depth.begin(), depth.end());
  for (int i = 1; (1 << i) <= max_depth; i++) {
    parent.push_back(std::vector<int>(tree.size(), -1));
    for (int j = 1; j < tree.size(); j++) {
      if (parent[i - 1][j] != -1) {
        parent[i][j] = parent[i - 1][parent[i - 1][j]];
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

      int diff = depth[v] - depth[u];

      for (int i = 0; diff > 0; i++) {
        if (diff & 1) {
          v = parent[i][v];
        }
        diff >>= 1;
      }
    }

    if (u != v) {
      for (int i = parent.size() - 1; i >= 0; i--) {
        if (parent[i][u] != -1 && parent[i][u] != parent[i][v]) {
          u = parent[i][u];
          v = parent[i][v];
        }
      }

      u = parent[0][u];
      v = parent[0][v];
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
