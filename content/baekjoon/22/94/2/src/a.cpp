#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

struct Point {
  int x;
  char op;
  int id;
};

bool solution(std::vector<std::pair<int, int>> &circles) {
  std::vector<Point> points;
  for (int i = 0; i < circles.size(); i++) {
    auto &[x, r] = circles[i];
    points.push_back({x - r, '(', i});
    points.push_back({x + r, ')', i});
  }

  std::sort(points.begin(), points.end(),
            [](const Point &p1, const Point &p2) { return p1.x < p2.x; });

  std::stack<int> stack;
  for (int i = 0; i < points.size(); i++) {
    if (points[i].op == '(') {
      stack.push(points[i].id);
    } else if (points[i].op == ')') {
      if (stack.empty() || stack.top() != points[i].id) {
        return false;
      } else {
        stack.pop();
      }
    }
  }

  return stack.empty();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> circles(n);
  for (auto &[x, r] : circles) {
    std::cin >> x >> r;
  }

  std::cout << (solution(circles) ? "YES\n" : "NO\n");

  return 0;
}
