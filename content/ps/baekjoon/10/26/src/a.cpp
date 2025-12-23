#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &a, std::vector<int> &b) {
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end());

  int result = 0;
  for (int i = 0; i < a.size(); i++) {
    result += a[i] * b[i];
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> a(n), b(n);

  for (int &i : a) {
    std::cin >> i;
  }

  for (int &i : b) {
    std::cin >> i;
  }

  std::cout << solution(a, b) << '\n';

  return 0;
}
