#include <functional>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<int> &array) {
  std::priority_queue<int> left;
  std::priority_queue<int, std::vector<int>, std::greater<>> right;

  std::vector<int> result;

  for (int i = 0; i < array.size(); i++) {
    if (left.size() == right.size()) {
      left.push(array[i]);
    } else {
      right.push(array[i]);
    }

    while (!left.empty() && !right.empty() && left.top() > right.top()) {
      int move = right.top();
      right.pop();

      right.push(left.top());
      left.pop();

      left.push(move);
    }

    if (i % 2 == 0) {
      result.push_back(left.top());
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0;
  std::vector<int> array;

  while (t--) {
    std::cin >> n;

    array.resize(n);
    for (int &i : array) {
      std::cin >> i;
    }

    std::vector<int> result = solution(array);

    std::cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
      if (i != 0 && i % 10 == 0) {
        std::cout << '\n';
      }

      std::cout << result[i] << ' ';
    }

    std::cout << '\n';
  }

  return 0;
}
