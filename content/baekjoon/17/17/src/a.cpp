#include <iostream>
#include <vector>

int find(std::vector<int> &parent, int x) {
  if (parent[x] == x) {
    return x;
  }

  return parent[x] = find(parent, parent[x]);
}

void merge(std::vector<int> &parent, int x, int y) {
  int p_x = find(parent, x);
  int p_y = find(parent, y);

  parent[p_x] = parent[p_y];
}

void solution(int n, int m) {
  std::vector<int> parent(n + 1);
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }

  int command, a, b;
  while (m--) {
    std::cin >> command >> a >> b;

    if (command) {
      std::cout << (find(parent, a) == find(parent, b) ? "YES\n" : "NO\n");
    } else {
      merge(parent, a, b);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  solution(n, m);

  return 0;
}
