#include <utility>
#include <vector>

class DSU {
public:
  DSU(int n);

  void merge(int x, int y);
  int find(int x);

private:
  std::vector<int> parent_;
  std::vector<int> size_;
};

DSU::DSU(int n) {
  parent_ = std::vector<int>(n);
  for (int i = 0; i < n; i++) {
    parent_[i] = i;
  }

  size_ = std::vector<int>(n, 1);
}

void DSU::merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }

  if (size_[x] > size_[y]) {
    std::swap(x, y);
  }

  parent_[x] = parent_[y];
  size_[y] += size_[x];
}

int DSU::find(int x) {
  if (parent_[x] == x) {
    return x;
  }

  return parent_[x] = (find(parent_[x]));
}
