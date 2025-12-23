#include <iostream>
#include <queue>
#include <vector>

bool solution(std::vector<std::vector<int>> &tree) {
  std::vector<int> distance(tree.size(), -1);
  std::queue<int> queue;

  int start = 1;
  distance[start] = 0;
  queue.push(start);

  int total = 0;
  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    int children = 0;

    for (int &adj : tree[front]) {
      if (distance[adj] == -1) {
        children++;
        distance[adj] = distance[front] + 1;
        queue.push(adj);
      }
    }

    if (children == 0) {
      total += distance[front];
    }
  }

  return total % 2 != 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> tree(n + 1);

  int u = 0, v = 0;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  std::cout << (solution(tree) ? "Yes\n" : "No\n");

  return 0;
}
