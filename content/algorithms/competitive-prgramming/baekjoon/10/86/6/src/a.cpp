#include <deque>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::deque<int> deque;

  std::string command;
  int value = 0;

  while (n--) {
    std::cin >> command;

    if (command == "push_front") {
      std::cin >> value;
      deque.push_front(value);
    } else if (command == "push_back") {
      std::cin >> value;
      deque.push_back(value);
    } else if (command == "pop_front") {
      if (deque.empty()) {
        std::cout << "-1\n";
      } else {
        std::cout << deque.front() << '\n';
        deque.pop_front();
      }
    } else if (command == "pop_back") {
      if (deque.empty()) {
        std::cout << "-1\n";
      } else {
        std::cout << deque.back() << '\n';
        deque.pop_back();
      }
    } else if (command == "size") {
      std::cout << deque.size() << '\n';
    } else if (command == "empty") {
      std::cout << (deque.empty() ? 1 : 0) << '\n';
    } else if (command == "front") {
      std::cout << (deque.empty() ? -1 : deque.front()) << '\n';
    } else if (command == "back") {
      std::cout << (deque.empty() ? -1 : deque.back()) << '\n';
    }
  }

  return 0;
}
