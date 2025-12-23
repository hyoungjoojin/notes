#include <iostream>
#include <vector>

using ll = long long;

ll solution(std::vector<int> &array) {
  int n = array.size();

  std::vector<ll> remainders(n, 0);
  remainders[0] = 1;

  ll psum = 0, count = 0;
  for (int i : array) {
    psum += i;

    int remainder = (psum % n + n) % n;
    count += remainders[remainder]++;
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array) << '\n';

  return 0;
}
