#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &a, std::vector<int> &b) {
  std::vector<int> result(a.size() + b.size());

  int x = 0, y = 0, i = 0;
  for (; x < a.size() && y < b.size();) {
    if (a[x] < b[y]) {
      result[i++] = a[x++];
    } else {
      result[i++] = b[y++];
    }
  }

  for (; x < a.size(); x++) {
    result[i++] = a[x];
  }

  for (; y < b.size(); y++) {
    result[i++] = b[y];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int &i : a) {
    std::cin >> i;
  }

  std::vector<int> b(m);
  for (int &i : b) {
    std::cin >> i;
  }

  std::vector<int> result = solution(a, b);
  for (int i : result) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
