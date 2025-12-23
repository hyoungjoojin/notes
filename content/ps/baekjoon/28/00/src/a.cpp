#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

void backtrack(std::vector<std::string> &result, std::string &input,
               std::vector<bool> &skip, std::vector<std::pair<int, int>> &pairs,
               int start) {
  if (start >= pairs.size()) {
    bool removed_nothing = true;
    for (bool p : skip) {
      if (p) {
        removed_nothing = false;
        break;
      }
    }

    if (!removed_nothing) {
      std::string output = "";
      for (int i = 0; i < skip.size(); i++) {
        if (!skip[i]) {
          output += input[i];
        }
      }
      result.push_back(output);
    }
    return;
  }

  skip[pairs[start].first] = false;
  skip[pairs[start].second] = false;
  backtrack(result, input, skip, pairs, start + 1);

  skip[pairs[start].first] = true;
  skip[pairs[start].second] = true;
  backtrack(result, input, skip, pairs, start + 1);
}

std::vector<std::string> solution(std::string &input) {
  std::stack<int> stack;
  std::vector<std::pair<int, int>> pairs;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '(') {
      stack.push(i);
    } else if (input[i] == ')') {
      pairs.push_back({stack.top(), i});
      stack.pop();
    }
  }

  std::vector<std::string> result;
  std::vector<bool> skip(input.size(), false);

  backtrack(result, input, skip, pairs, 0);
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::cin >> input;

  std::vector<std::string> result = solution(input);
  std::sort(result.begin(), result.end());

  std::cout << result[0] << '\n';
  for (int i = 1; i < result.size(); i++) {
    if (result[i] == result[i - 1]) {
      continue;
    }

    std::cout << result[i] << '\n';
  }

  return 0;
}
