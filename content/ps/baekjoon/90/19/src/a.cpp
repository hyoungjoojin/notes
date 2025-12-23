#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

int d(int x) { return (x * 2) % 10000; }

int s(int x) { return (x == 0) ? 9999 : x - 1; }

int l(int x) { return (x * 10) % 10000 + (x / 1000); }

int r(int x) { return (x % 10) * 1000 + (x / 10); }

std::string solution(int a, int b) {
  std::queue<int> queue;
  std::vector<bool> visited(10000, false);
  std::vector<std::pair<int, char>> previous(10000, {0, ' '});

  char commands[4] = {'D', 'S', 'L', 'R'};
  std::function<int(int)> functions[4] = {d, s, l, r};

  queue.push(a);
  visited[a] = true;
  previous[a].first = a;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int i = 0; i < 4; i++) {
      int next = functions[i](front);

      if (next >= 0 && next < visited.size() && !visited[next]) {
        queue.push(next);
        visited[next] = true;
        previous[next].first = front;
        previous[next].second = commands[i];
      }
    }
  }

  std::stack<char> stack;
  while (previous[b].first != b) {
    stack.push(previous[b].second);
    b = previous[b].first;
  }

  std::string result;
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int a = 0, b = 0;
  while (t--) {
    std::cin >> a >> b;
    std::cout << solution(a, b) << '\n';
  }

  return 0;
}
