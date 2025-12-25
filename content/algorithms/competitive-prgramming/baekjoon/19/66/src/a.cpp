#include <array>
#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<int> &array, int m) {
  std::array<int, 10> count = {0};
  std::queue<int> queue;

  for (int i = 0; i < array.size(); i++) {
    count[array[i]]++;
    queue.push(i);
  }

  int order = 0;
  while (!queue.empty()) {
    bool found = false;
    for (int i = array[queue.front()] + 1; i < 10; i++) {
      if (count[i] != 0) {
        queue.push(queue.front());
        queue.pop();
        found = true;
        break;
      }
    }

    if (found) {
      continue;
    }

    int front = queue.front();
    count[array[front]]--;
    queue.pop();

    order++;

    if (front == m) {
      break;
    }
  }

  return order;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int n = 0, m = 0;
  std::vector<int> array;
  while (t--) {
    std::cin >> n >> m;
    array.resize(n);

    for (int &i : array) {
      std::cin >> i;
    }

    std::cout << solution(array, m) << '\n';
  }

  return 0;
}
