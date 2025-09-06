#include <iostream>
#include <map>
#include <vector>

long long solution(std::vector<int> &array, int target) {
  long long count = 0, psum = 0;

  std::map<long long, long long> map;
  map[0] = 1;

  for (long long i : array) {
    psum += i;

    count += map[psum - target];
    map[psum]++;
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, x = 0;
  std::cin >> n >> x;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::cout << solution(array, x) << '\n';

  return 0;
}
