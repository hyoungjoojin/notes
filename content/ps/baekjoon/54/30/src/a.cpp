#include <deque>
#include <iostream>
#include <string>

std::string solution(std::string &command, int n, std::string &input) {
  std::deque<int> deque;

  for (int i = 1; i < input.size() - 1; i++) {
    std::string number;

    while (input[i] != ',' && input[i] != ']') {
      number += input[i];
      i++;
    }

    deque.push_back(std::stoi(number));
  }

  bool reversed = false;
  for (char ch : command) {
    if (ch == 'R') {
      reversed = !reversed;
    } else if (ch == 'D') {
      if (deque.empty()) {
        return "error";
      }

      if (reversed) {
        deque.pop_back();
      } else {
        deque.pop_front();
      }
    }
  }

  std::string output = "[";

  while (deque.size() > 1) {
    if (reversed) {
      output += std::to_string(deque.back());
      output += ',';
      deque.pop_back();
    } else {
      output += std::to_string(deque.front());
      output += ',';
      deque.pop_front();
    }
  }

  if (!deque.empty()) {
    output += std::to_string(deque.front());
  }

  output += ']';

  return output;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  std::string command, input;

  while (t--) {
    std::cin >> command >> n >> input;
    std::cout << solution(command, n, input) << '\n';
  }

  return 0;
}
