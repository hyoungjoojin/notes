#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

std::vector<int> solution(std::vector<int> &array) {
  std::unordered_map<int, int> freq;
  for (int &i : array) {
    freq[i]++;
  }

  std::vector<int> result(array.size());

  std::stack<int> stack;
  for (int i = array.size() - 1; i >= 0; i--) {
    while (!stack.empty() && freq[stack.top()] <= freq[array[i]]) {
      stack.pop();
    }

    result[i] = stack.empty() ? -1 : stack.top();
    stack.push(array[i]);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  std::vector<int> result = solution(array);
  for (int &i : result) {
    std::cout << i << ' ';
  }

  return 0;
}
