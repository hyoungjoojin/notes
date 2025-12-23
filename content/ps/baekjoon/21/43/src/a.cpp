#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

long solution(std::vector<long> &a, std::vector<long> &b, long target) {
  for (int i = 1; i < a.size(); i++) {
    a[i] += a[i - 1];
  }

  for (int i = 1; i < b.size(); i++) {
    b[i] += b[i - 1];
  }

  std::vector<long> a_sum, b_sum;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      a_sum.push_back(a[j] - a[i]);
    }
  }

  for (int i = 0; i < b.size(); i++) {
    for (int j = i + 1; j < b.size(); j++) {
      b_sum.push_back(b[j] - b[i]);
    }
  }

  std::unordered_map<long, long> map;
  for (int i = 0; i < a_sum.size(); i++) {
    map[a_sum[i]]++;
  }

  std::sort(b_sum.begin(), b_sum.end());

  long count = 0;
  for (auto &[key, value] : map) {
    count +=
        value * (std::upper_bound(b_sum.begin(), b_sum.end(), target - key) -
                 std::lower_bound(b_sum.begin(), b_sum.end(), target - key));
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long t = 0;
  std::cin >> t;

  int n = 0, m = 0;

  std::cin >> n;
  std::vector<long> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::cin >> m;
  std::vector<long> b(m + 1);
  b[0] = 0;
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }

  std::cout << solution(a, b, t) << '\n';

  return 0;
}
