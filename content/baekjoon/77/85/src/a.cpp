#include <functional>
#include <iostream>
#include <map>
#include <string>

using Log = std::map<std::string, bool, std::greater<std::string>>;

void solution(Log &log) {
  for (auto &[name, present] : log) {
    if (present) {
      std::cout << name << '\n';
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  Log log;

  std::string name, command;
  while (n--) {
    std::cin >> name >> command;
    log[name] = (command[0] == 'e');
  }

  solution(log);

  return 0;
}
