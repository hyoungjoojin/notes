#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> solution_(std::vector<std::pair<int, int>> &memo,
                              std::vector<int> &visited,
                              std::vector<std::vector<int>> &tree,
                              std::vector<int> &people, int start) {
  if (memo[start].first != -1 && memo[start].second != -1) {
    return memo[start];
  }

  visited[start] = 1;

  int take = people[start], skip = 0;
  for (int &adj : tree[start]) {
    if (!visited[adj]) {
      take += solution_(memo, visited, tree, people, adj).second;
      skip += std::max(solution_(memo, visited, tree, people, adj).first,
                       solution_(memo, visited, tree, people, adj).second);
    }
  }

  memo[start].first = take;
  memo[start].second = skip;
  return {take, skip};
}

int solution(std::vector<std::vector<int>> &tree, std::vector<int> &people) {
  std::vector<std::pair<int, int>> memo(people.size(), {-1, -1});
  std::vector<int> visited(people.size(), 0);

  auto [take, skip] = solution_(memo, visited, tree, people, 1);
  return std::max(take, skip);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> people(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> people[i];
  }

  std::vector<std::vector<int>> tree(n + 1, std::vector<int>());

  int u, v;
  for (int i = 1; i < n; i++) {
    std::cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  std::cout << solution(tree, people) << '\n';

  return 0;
}
