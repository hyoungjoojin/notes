#include <iostream>
#include <queue>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::queue<int> queue;

  std::string command;
  int value = 0;

  while (n--) {
    std::cin >> command;

    if (command == "push") {
      std::cin >> value;
      queue.push(value);
      continue;
    }

    if (queue.empty()) {
      switch (command[0]) {
      case 'p': // pop
      case 'f': // front
      case 'b': // back
        std::cout << "-1\n";
        break;

      case 's': // size
        std::cout << "0\n";
        break;

      case 'e': // empty
        std::cout << "1\n";
        break;

      default:
        break;
      }
    } else {
      switch (command[0]) {
      case 'p': // pop
        std::cout << queue.front() << '\n';
        queue.pop();
        break;

      case 's': // size
        std::cout << queue.size() << '\n';
        break;

      case 'e': // empty
        std::cout << "0\n";
        break;

      case 'f': // front
        std::cout << queue.front() << '\n';
        break;

      case 'b': // back
        std::cout << queue.back() << '\n';
        break;

      default:
        break;
      }
    }
  }

  return 0;
}
