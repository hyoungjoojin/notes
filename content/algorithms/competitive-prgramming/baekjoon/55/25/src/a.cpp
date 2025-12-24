#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<char> &input, int chunk_size) {
  int result = 0;

  int current_chunk_size = 0;
  bool started = false;
  char expected = 'O';

  for (int i = 0; i < input.size(); i++) {
    if (started && input[i] == expected) {
      if (input[i] == 'I') {
        expected = 'O';
        current_chunk_size++;
      } else {
        expected = 'I';
      }
      continue;
    }

    if (started) {
      result += std::max(current_chunk_size - chunk_size + 1, 0);
      started = false;
    }

    if (!started) {
      if (input[i] == 'I') {
        current_chunk_size = 0;
        started = true;
        expected = 'O';
      }
      continue;
    }
  }

  if (started) {
    result += std::max(current_chunk_size - chunk_size + 1, 0);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<char> input(m);
  for (char &ch : input) {
    std::cin >> ch;
  }

  std::cout << solution(input, n) << '\n';

  return 0;
}
