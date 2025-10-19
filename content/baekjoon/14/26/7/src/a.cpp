#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> solution(std::vector<int> &parent,
                          std::vector<std::pair<int, int>> &rewards) {
  std::vector<std::vector<int>> tree(parent.size(), std::vector<int>());
  for (int i = 2; i < parent.size(); i++) {
    tree[parent[i]].push_back(i);
  }

  std::vector<int> result(parent.size(), 0);
  for (auto &[i, value] : rewards) {
    result[i] += value;
  }

  std::queue<int> queue;
  queue.push(1);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adj : tree[front]) {
      queue.push(adj);
      result[adj] += result[front];
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> parent[i];
  }

  std::vector<std::pair<int, int>> rewards(m);
  for (auto &[i, value] : rewards) {
    std::cin >> i >> value;
  }

  std::vector<int> result = solution(parent, rewards);
  for (int i = 1; i <= n; i++) {
    std::cout << result[i] << ' ';
  }

  return 0;
}
