#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &a, std::vector<int> &b) {
  std::sort(b.begin(), b.end());

  int count = 0;
  for (int i : a) {
    int index = -1;

    for (int li = 0, ri = b.size() - 1; li <= ri;) {
      int mid = (li + ri) / 2;

      if (b[mid] < i) {
        index = std::max(index, mid);
        li = mid + 1;
      } else if (b[mid] >= i) {
        ri = mid - 1;
      }
    }

    count += (index + 1);
  }
  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n, m;
  std::vector<int> a, b;

  while (t--) {
    std::cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for (int &i : a) {
      std::cin >> i;
    }

    for (int &i : b) {
      std::cin >> i;
    }

    std::cout << solution(a, b) << '\n';
  }

  return 0;
}
