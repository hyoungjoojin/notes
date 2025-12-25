#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

std::array<bool, 10001> is_prime;
std::vector<int> distance(10001, -1);

int solution(int from, int to) {
  std::fill(distance.begin(), distance.end(), -1);
  std::queue<int> queue;

  distance[from] = 0;
  queue.push(from);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == to) {
      return distance[front];
    }

    int digits[4] = {0}, tens[4] = {1000, 100, 10, 1};
    for (int i = 3, target = front; i >= 0; i--) {
      digits[i] = target % 10;
      target /= 10;
    }

    int next = front;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 10; j++) {
        next -= (digits[i] * tens[i]);
        next += (j * tens[i]);

        if (next >= 1000 && is_prime[next] && distance[next] == -1) {
          distance[next] = distance[front] + 1;
          queue.push(next);
        }

        next -= (j * tens[i]);
        next += (digits[i] * tens[i]);
      }
    }
  }

  return -1;
}

void fill_primes() {
  std::fill(is_prime.begin(), is_prime.end(), true);

  for (int i = 2; i * i < is_prime.size(); i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j < is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  fill_primes();

  int t = 0;
  std::cin >> t;

  int from, to;
  while (t--) {
    std::cin >> from >> to;

    int result = solution(from, to);
    std::cout << (result == -1 ? "impossible" : "") << result << '\n';
  }

  return 0;
}
