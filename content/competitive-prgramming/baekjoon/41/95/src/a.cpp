#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int find(std::vector<int> &parent, int x) {
  if (x == parent[x]) {
    return x;
  }

  return parent[x] = find(parent, parent[x]);
}

void merge(std::vector<int> &parent, std::vector<int> &size, int x, int y) {
  x = find(parent, x);
  y = find(parent, y);

  if (x != y) {
    if (size[x] < size[y]) {
      std::swap(x, y);
    }

    parent[y] = x;
    size[x] += size[y];
  }
}

void solution(int n) {
  std::unordered_map<std::string, int> map;

  std::vector<int> parent;
  std::vector<int> size;

  std::string a, b;
  while (n--) {
    std::cin >> a >> b;

    if (map.find(a) == map.end()) {
      int index = parent.size();
      map[a] = index;
      parent.push_back(index);
      size.push_back(1);
    }

    if (map.find(b) == map.end()) {
      int index = parent.size();
      map[b] = index;
      parent.push_back(index);
      size.push_back(1);
    }

    merge(parent, size, map[a], map[b]);

    int root = find(parent, map[a]);
    std::cout << size[root] << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  while (t--) {
    std::cin >> n;

    solution(n);
  }

  return 0;
}
