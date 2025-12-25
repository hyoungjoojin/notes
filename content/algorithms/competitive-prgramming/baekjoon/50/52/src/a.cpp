#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Node {
  bool used = false;
  std::array<std::shared_ptr<Node>, 10> children;

  Node() {
    used = false;
    for (int i = 0; i < children.size(); i++) {
      children[i] = nullptr;
    }
  }
};

bool solution(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());

  std::shared_ptr<Node> root = std::make_shared<Node>();

  for (std::string &word : words) {
    std::shared_ptr<Node> cursor = root;

    for (char ch : word) {
      if (cursor->children[ch - '0'] == nullptr) {
        cursor->children[ch - '0'] = std::make_shared<Node>();
      }

      if (cursor->children[ch - '0']->used) {
        return false;
      }

      cursor = cursor->children[ch - '0'];
    }

    cursor->used = true;
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  std::vector<std::string> array;

  while (t--) {
    std::cin >> n;
    array.resize(n);

    for (std::string &i : array) {
      std::cin >> i;
    }

    std::cout << (solution(array) ? "YES\n" : "NO\n");
  }

  return 0;
}
