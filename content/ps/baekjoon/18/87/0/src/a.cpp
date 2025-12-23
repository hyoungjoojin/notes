#include <algorithm>
#include <iostream>
#include <vector>

void solution(std::vector<int> &numbers) {
  std::vector<int> sorted(numbers.size());
  for (int i = 0; i <= numbers.size(); i++) {
    sorted[i] = numbers[i];
  }

  std::sort(sorted.begin(), sorted.end());

  int size = 0;
  for (int i = 0; i < sorted.size(); i++) {
    if (i == 0 || sorted[i] != sorted[i - 1]) {
      sorted[size++] = sorted[i];
    }
  }
  sorted.resize(size);

  for (int i = 0; i < numbers.size(); i++) {
    int upper_bound = -1;
    for (int li = 0, ri = size - 1; li <= ri;) {
      int mid = (li + ri) / 2;

      if (sorted[mid] < numbers[i]) {
        upper_bound = std::max(upper_bound, mid);
        li = mid + 1;
      } else {
        ri = mid - 1;
      }
    }

    numbers[i] = upper_bound + 1;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &number : numbers) {
    std::cin >> number;
  }

  solution(numbers);
  for (int i : numbers) {
    std::cout << i << ' ';
  }

  return 0;
}
