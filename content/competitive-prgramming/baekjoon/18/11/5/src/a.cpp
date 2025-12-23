#include <deque>
#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &commands) {
  std::deque<int> deque;

  for (int i = 1; i <= commands.size(); i++) {
    int command = commands[commands.size() - i];
    if (command == 1) {
      deque.push_front(i);
    } else if (command == 2) {
      int front = deque.front();
      deque.pop_front();

      deque.push_front(i);
      deque.push_front(front);
    } else {
      deque.push_back(i);
    }
  }

  std::vector<int> result;
  while (!deque.empty()) {
    result.push_back(deque.front());
    deque.pop_front();
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> commands(n);
  for (int &i : commands) {
    std::cin >> i;
  }

  std::vector<int> result = solution(commands);
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
