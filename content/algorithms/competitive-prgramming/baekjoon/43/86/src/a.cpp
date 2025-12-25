#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

double solution(std::vector<std::pair<double, double>> &points) {
  std::vector<std::vector<std::pair<int, double>>> graph(points.size());
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      double dx = (points[i].first - points[j].first),
             dy = (points[i].second - points[j].second);
      double distance = std::sqrt(dx * dx + dy * dy);

      graph[i].push_back({j, distance});
      graph[j].push_back({i, distance});
    }
  }

  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>, std::greater<>>
      pq;
  std::vector<bool> visited(points.size(), false);
  double result = 0.0;

  pq.push({0.0, 0});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (visited[v]) {
      continue;
    }

    visited[v] = true;
    result += d_v;

    for (auto &[adj, w] : graph[v]) {
      if (!visited[adj]) {
        pq.push({w, adj});
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cout.precision(2);
  std::cout << std::fixed;

  int n = 0;
  std::cin >> n;

  std::vector<std::pair<double, double>> points(n);
  for (auto &[x, y] : points) {
    std::cin >> x >> y;
  }

  std::cout << solution(points) << '\n';

  return 0;
}
