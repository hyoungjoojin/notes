#include <deque>
#include <iostream>
#include <string>

bool solution(std::string &input, std::string &output) {
  std::deque<char> deque;
  for (char ch : output) {
    deque.push_back(ch);
  }

  bool reversed = false;
  while (deque.size() != input.size()) {
    char end = (reversed ? deque.front() : deque.back());

    if (reversed) {
      deque.pop_front();
    } else {
      deque.pop_back();
    }

    if (end == 'B') {
      reversed = !reversed;
    }
  }

  for (char ch : input) {
    char x;

    if (reversed) {
      x = deque.back();
      deque.pop_back();
    } else {
      x = deque.front();
      deque.pop_front();
    }

    if (ch != x) {
      return false;
    }
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string a, b;
  std::cin >> a >> b;

  std::cout << (solution(a, b) ? "1\n" : "0\n");

  return 0;
}
