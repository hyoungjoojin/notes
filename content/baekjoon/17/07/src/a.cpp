#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

bool solution(Graph &graph) {
  std::vector<int> color(graph.size(), -1);

  for (int i = 1; i < graph.size(); i++) {
    if (color[i] != -1) {
      continue;
    }

    std::queue<int> queue;

    color[i] = 0;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int adj : graph[front]) {
        if (color[adj] == -1) {
          color[adj] = 1 - color[front];
          queue.push(adj);
        } else if ((color[front] ^ color[adj]) == 0) {
          return false;
        }
      }
    }
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  while (t--) {
    int v = 0, e = 0;
    std::cin >> v >> e;

    Graph graph(v + 1);

    int a, b;
    while (e--) {
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    std::cout << (solution(graph) ? "YES\n" : "NO\n");
  }

  return 0;
}
