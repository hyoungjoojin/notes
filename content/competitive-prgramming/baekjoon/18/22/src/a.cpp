#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &a, std::vector<int> &b) {
  std::vector<int> result;

  std::sort(b.begin(), b.end());
  for (int i : a) {
    if (!std::binary_search(b.begin(), b.end(), i)) {
      result.push_back(i);
    }
  }

  std::sort(result.begin(), result.end());
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> a(n), b(m);

  for (int &i : a) {
    std::cin >> i;
  }

  for (int &i : b) {
    std::cin >> i;
  }

  std::vector<int> result = solution(a, b);

  std::cout << result.size() << '\n';
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
