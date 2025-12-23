#include <deque>
#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &balloons) {
  std::vector<int> result(balloons.size());

  std::deque<int> deque;
  for (int i = 1; i <= balloons.size(); i++) {
    deque.push_back(i);
  }

  int index = 0;
  while (!deque.empty()) {
    int front = deque.front();
    deque.pop_front();

    int iter = balloons[front - 1];
    if (iter > 0) {
      while (iter-- > 1) {
        deque.push_back(deque.front());
        deque.pop_front();
      }
    } else if (iter < 0) {
      while (iter++ < 0) {
        deque.push_front(deque.back());
        deque.pop_back();
      }
    }

    result[index++] = front;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> balloons(n);
  for (int &b : balloons) {
    std::cin >> b;
  }

  std::vector<int> result = solution(balloons);
  for (int i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
