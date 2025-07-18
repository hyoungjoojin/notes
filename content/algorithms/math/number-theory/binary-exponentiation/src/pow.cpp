#include <iostream>

// Compute a^b mod m
int pow(int a, int b, int m) {
  int res = 1;

  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % m;
    }

    a = (a * a) % m;

    b /= 2;
  }

  return res;
}

int main() {
  std::cout << "pow(26, 100000) mod 17 = " << pow(26, 100000, 17) << std::endl;
  return 0;
}
