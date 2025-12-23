#include <iostream>
#include <vector>

void solution_(std::vector<int> &slots, std::vector<bool> &visited, int start) {
  if (start == visited.size()) {
    for (int i : slots) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      visited[i] = true;
      slots[start] = i + 1;
      solution_(slots, visited, start + 1);
      visited[i] = false;
    }
  }
}

void solution(int n) {
  std::vector<int> slots(n);
  std::vector<bool> visited(n, false);
  solution_(slots, visited, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}
