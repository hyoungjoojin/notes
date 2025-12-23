#include <iostream>

int solution(int a, int b) {
  if (b == 1) {
    return 0;
  }

  int n = 1;
  for (int i = a; i < b; i += (a - 1), n++)
    ;
  return n;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0;
  std::cin >> a >> b;

  std::cout << solution(a, b) << '\n';

  return 0;
}
