#include <iostream>
#include <vector>

void solution_(std::vector<std::vector<int>> &result, std::vector<int> &inorder,
               int start, int end, int level) {
  int size = end - start + 1;
  int mid = (size - 1) / 2 + start;

  if (mid == start) {
    result[level].push_back(inorder[mid]);
    return;
  }

  solution_(result, inorder, start, mid - 1, level + 1);
  result[level].push_back(inorder[mid]);
  solution_(result, inorder, mid + 1, end, level + 1);
}

std::vector<std::vector<int>> solution(std::vector<int> &inorder, int depth) {
  std::vector<std::vector<int>> result(depth);

  solution_(result, inorder, 0, inorder.size() - 1, 0);

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k = 0;
  std::cin >> k;

  int size = 1;
  for (int i = 0; i < k; i++) {
    size *= 2;
  }
  size--;

  std::vector<int> inorder(size);
  for (int &i : inorder) {
    std::cin >> i;
  }

  std::vector<std::vector<int>> result = solution(inorder, k);
  for (auto &row : result) {
    for (int &i : row) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
