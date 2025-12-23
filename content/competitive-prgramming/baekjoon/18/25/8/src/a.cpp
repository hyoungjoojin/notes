#include <iostream>
#include <queue>

void solution(std::queue<int> &queue, std::string &command) {
  if (command == "push") {
    int value = 0;
    std::cin >> value;
    queue.push(value);
    return;
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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::queue<int> queue;

  std::string command;

  while (n--) {
    std::cin >> command;
    solution(queue, command);
  }

  return 0;
}
