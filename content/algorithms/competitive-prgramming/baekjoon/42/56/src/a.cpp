#include <iostream>
#include <vector>

void solution_(const std::vector<int> &preorder,
               const std::vector<int> &inorder, std::vector<int> &postorder,
               int preorder_start, int preorder_end, int inorder_start,
               int inorder_end, int postorder_start, int postorder_end) {
  int mid = preorder[preorder_start];
  postorder[postorder_end] = mid;

  if (postorder_start == postorder_end) {
    return;
  }

  int left_length = 0;
  for (int i = inorder_start; i <= inorder_end; i++) {
    if (inorder[i] == mid) {
      break;
    }

    left_length++;
  }

  if (left_length > 0) {
    solution_(preorder, inorder, postorder, preorder_start + 1,
              preorder_start + left_length, inorder_start,
              inorder_start + left_length - 1, postorder_start,
              postorder_start + left_length - 1);
  }

  if (postorder_end - postorder_start - left_length > 0) {
    solution_(preorder, inorder, postorder, preorder_start + left_length + 1,
              preorder_end, inorder_start + left_length + 1, inorder_end,
              postorder_start + left_length, postorder_end - 1);
  }
}

std::vector<int> solution(std::vector<int> &preorder,
                          std::vector<int> &inorder) {
  std::vector<int> postorder(preorder.size(), 0);
  solution_(preorder, inorder, postorder, 0, preorder.size() - 1, 0,
            inorder.size() - 1, 0, postorder.size() - 1);

  return postorder;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  std::vector<int> preorder, inorder;

  while (t--) {
    std::cin >> n;
    preorder.resize(n);
    inorder.resize(n);

    for (int &i : preorder) {
      std::cin >> i;
    }

    for (int &i : inorder) {
      std::cin >> i;
    }

    std::vector<int> postorder = solution(preorder, inorder);
    for (int &i : postorder) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
