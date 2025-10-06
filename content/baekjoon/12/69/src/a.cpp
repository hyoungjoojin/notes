#include <iostream>
#include <unordered_map>
#include <vector>

int solution(std::vector<int> &a, std::vector<int> &b) {
  std::unordered_map<int, int> u;
  for (int i : a) {
    u[i] = 1;
  }

  for (int i : b) {
    u[i] = 1;
  }

  std::unordered_map<int, int> m;
  for (int i : a) {
    m[i] = 1;
  }

  int count = 0;
  for (int i : b) {
    if (m[i] == 1) {
      count++;
      m[i] = 0;
    }
  }

  return u.size() - count;
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

  std::cout << solution(a, b) << '\n';

  return 0;
}
