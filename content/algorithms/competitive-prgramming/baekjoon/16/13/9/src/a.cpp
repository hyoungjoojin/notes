#include <iostream>
#include <string>
#include <vector>

void solution(std::string &word, int num_queries) {
  std::vector<std::vector<int>> pcount('z' - 'a' + 1,
                                       std::vector<int>(word.size() + 1, 0));
  for (int i = 0; i < ('z' - 'a' + 1); i++) {
    char ch = i + 'a';
    int count = 0;

    for (int j = 0; j < word.size(); j++) {
      if (ch == word[j]) {
        count++;
      }

      pcount[i][j + 1] = count;
    }
  }

  char alphabet;
  int start, end;

  while (num_queries--) {
    std::cin >> alphabet >> start >> end;
    std::cout << pcount[alphabet - 'a'][end + 1] - pcount[alphabet - 'a'][start]
              << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::cin >> input;

  int q = 0;
  std::cin >> q;

  solution(input, q);

  return 0;
}
