#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

void solution(std::vector<std::string> &names,
              std::unordered_map<std::string, int> dictionary,
              std::vector<std::vector<int>> &graph) {
  std::vector<int> inbound(graph.size(), 0);
  for (auto &adj_list : graph) {
    for (int &adj : adj_list) {
      inbound[adj]++;
    }
  }

  std::vector<int> roots;
  std::vector<std::vector<int>> children(graph.size());
  std::vector<bool> visited(graph.size(), false);
  std::queue<int> queue;

  for (int i = 0; i < graph.size(); i++) {
    if (inbound[i] == 0) {
      roots.push_back(i);
      visited[i] = true;
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : graph[front]) {
      if (visited[adj]) {
        continue;
      }

      if (--inbound[adj] == 0) {
        children[front].push_back(adj);
        visited[adj] = true;
        queue.push(adj);
      }
    }
  }

  std::cout << roots.size() << '\n';
  for (int i : roots) {
    std::cout << names[i] << ' ';
  }
  std::cout << '\n';

  for (auto &c : children) {
    std::sort(c.begin(), c.end());
  }

  for (int i = 0; i < graph.size(); i++) {
    std::cout << names[i] << ' ';

    std::cout << children[i].size() << ' ';

    for (int i : children[i]) {
      std::cout << names[i] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::string> names(n);
  std::unordered_map<std::string, int> dictionary;

  for (int i = 0; i < n; i++) {
    std::cin >> names[i];
  }

  std::sort(names.begin(), names.end());
  for (int i = 0; i < n; i++) {
    dictionary[names[i]] = i;
  }

  int m = 0;
  std::cin >> m;

  std::vector<std::vector<int>> graph(n);

  std::string child, ancestor;
  while (m--) {
    std::cin >> child >> ancestor;
    graph[dictionary[ancestor]].push_back(dictionary[child]);
  }

  solution(names, dictionary, graph);

  return 0;
}
