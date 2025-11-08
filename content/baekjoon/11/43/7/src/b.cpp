#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void solution(std::vector<std::vector<int>> &tree, int m) {
  std::queue<int> queue;
  std::vector<std::vector<int>> parent;
  std::vector<int> depth(tree.size(), -1);

  queue.push(1);
  parent.push_back(std::vector<int>(tree.size(), -1));
  depth[1] = 1;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : tree[front]) {
      if (depth[adj] == -1) {
        queue.push(adj);
        parent[0][adj] = front;
        depth[adj] = depth[front] + 1;
      }
    }
  }

  int max_depth = *std::max_element(depth.begin(), depth.end());
  for (int d = 1; (1 << d) <= max_depth; d++) {
    parent.push_back(std::vector<int>(tree.size(), -1));
    for (int k = 1; k < tree.size(); k++) {
      if (parent[d - 1][k] != -1) {
        parent[d][k] = parent[d - 1][parent[d - 1][k]];
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

      for (int diff = depth[v] - depth[u], i = 0; diff > 0; i++) {
        if (diff & 1) {
          v = parent[i][v];
        }

        diff >>= 1;
      }
    }

    if (u != v) {
      for (int d = parent.size() - 1; d >= 0; d--) {
        if (parent[d][u] != -1 && parent[d][u] != parent[d][v]) {
          u = parent[d][u];
          v = parent[d][v];
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
