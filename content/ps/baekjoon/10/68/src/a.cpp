#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<int> &parents, int remove) {
  std::vector<std::vector<int>> tree(parents.size());
  std::vector<int> visited(parents.size(), 0);
  std::queue<int> queue;

  for (int i = 0; i < parents.size(); i++) {
    if (parents[i] == -1) {
      continue;
    }

    tree[i].push_back(parents[i]);
    tree[parents[i]].push_back(i);
  }

  for (int i = 0; i < parents.size(); i++) {
    if (i == remove) {
      visited[i] = 1;
      continue;
    }

    if (parents[i] == -1) {
      visited[i] = 1;
      queue.push(i);
    }
  }

  int count = 0;
  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    int children = 0;
    for (int adj : tree[front]) {
      if (visited[adj]) {
        continue;
      }

      children++;
      visited[adj] = 1;
      queue.push(adj);
    }

    if (children == 0) {
      count++;
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> parents(n);
  for (int &parent : parents) {
    std::cin >> parent;
  }

  int remove = 0;
  std::cin >> remove;

  std::cout << solution(parents, remove) << '\n';

  return 0;
}
