#include <iostream>

int solution(int x) {
  if (x == 1) {
    return 0;
  }

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  int target = 0, count = 0;
  while (n--) {
    std::cin >> target;
    count += solution(target);
  }

  std::cout << count << '\n';
  return 0;
}
