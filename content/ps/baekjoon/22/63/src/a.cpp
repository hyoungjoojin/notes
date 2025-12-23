#include <iostream>
#include <vector>

void solution_(const std::vector<int> &inorder,
               const std::vector<int> &postorder, std::vector<int> &preorder,
               int inorder_start, int inorder_end, int postorder_start,
               int postorder_end, int preorder_start, int preorder_end) {
  if (preorder_start == preorder_end) {
    preorder[preorder_start] = postorder[postorder_end];
    return;
  }

  int mid = postorder[postorder_end];

  int left_size = 0;
  for (int i = inorder_start; i <= inorder_end; i++) {
    if (inorder[i] == mid) {
      break;
    }

    left_size++;
  }

  preorder[preorder_start] = mid;

  if (left_size > 0) {
    solution_(inorder, postorder, preorder, inorder_start,
              inorder_start + left_size - 1, postorder_start,
              postorder_start + left_size - 1, preorder_start + 1,
              preorder_start + left_size);
  }

  if (inorder_end - inorder_start > left_size) {
    solution_(inorder, postorder, preorder, inorder_start + left_size + 1,
              inorder_end, postorder_start + left_size, postorder_end - 1,
              preorder_start + left_size + 1, preorder_end);
  }
}

std::vector<int> solution(std::vector<int> &inorder,
                          std::vector<int> &postorder) {
  int n = inorder.size();

  std::vector<int> preorder(n, 0);
  solution_(inorder, postorder, preorder, 0, n - 1, 0, n - 1, 0, n - 1);

  return preorder;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> inorder(n), postorder(n);

  for (int &i : inorder) {
    std::cin >> i;
  }

  for (int &i : postorder) {
    std::cin >> i;
  }

  std::vector<int> result = solution(inorder, postorder);
  for (int &i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
