#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  std::string key;
  std::vector<Node> nodes;
  std::unordered_map<std::string, int> map;
};

void solution_(Node *node, int level) {
  for (int i = 0; i < level; i++) {
    std::cout << "--";
  }
  std::cout << node->key << '\n';

  std::sort(node->nodes.begin(), node->nodes.end(),
            [](const Node &a, const Node &b) { return a.key < b.key; });
  for (Node &n : node->nodes) {
    solution_(&n, level + 1);
  }
}

void solution(int n) {
  Node root;

  int k = 0;
  while (n--) {
    std::cin >> k;

    Node *current = &root;
    std::string next;

    while (k--) {
      std::cin >> next;

      if (current->map.find(next) == current->map.end()) {
        int index = current->nodes.size();
        current->map[next] = index;
        current->nodes.push_back(Node());
        current->nodes[index].key = next;
      }

      current = &(current->nodes[current->map[next]]);
    }
  }

  std::sort(root.nodes.begin(), root.nodes.end(),
            [](const Node &a, const Node &b) { return a.key < b.key; });
  for (Node &n : root.nodes) {
    solution_(&n, 0);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}
