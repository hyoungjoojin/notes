#include <algorithm>
#include <iostream>
#include <vector>

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

bool is_vowel(char ch) {
  for (char v : vowels) {
    if (v == ch) {
      return true;
    }
  }

  return false;
}

void solution_(std::vector<char> &target, int i, int length,
               std::vector<char> &characters, int j, int vowel_count) {
  if (i == length) {
    if (vowel_count >= 1 && (length - vowel_count) >= 2) {
      for (char ch : target) {
        std::cout << ch;
      }
      std::cout << '\n';
    }
    return;
  }

  for (int next = j; next < characters.size(); next++) {
    target[i] = characters[next];

    solution_(target, i + 1, length, characters, next + 1,
              vowel_count + (is_vowel(characters[next]) ? 1 : 0));
  }
}

void solution(std::vector<char> &characters, int length) {
  std::sort(characters.begin(), characters.end());
  std::vector<char> target(length);

  solution_(target, 0, length, characters, 0, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int l = 0, c = 0;
  std::cin >> l >> c;

  std::vector<char> characters(c);
  for (char &ch : characters) {
    std::cin >> ch;
  }

  solution(characters, l);

  return 0;
}
