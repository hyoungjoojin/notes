#include <algorithm>
#include <iostream>
#include <string>

int solution(std::string &dna) {
  int max = 1, currentCount = 1;
  char currentChar = dna[0];

  for (int i = 1; i < dna.size(); i++) {
    if (currentChar == dna[i]) {
      currentCount++;
    } else {
      max = std::max(max, currentCount);
      currentCount = 1;
      currentChar = dna[i];
    }
  }

  return std::max(max, currentCount);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string dna;
  std::cin >> dna;

  std::cout << solution(dna) << '\n';

  return 0;
}
