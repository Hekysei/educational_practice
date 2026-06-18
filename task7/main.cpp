#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  bool res = true;

  for (int i : {0, 4, 5}) {
    char c = s[i];
    if (!(c >= 65 && c <= 90)) {
      res = false;
    }
  }
  for (int i : {1, 2, 3}) {
    char c = s[i];
    if (!(c >= 48 && c <= 57)) {
      res = false;
    }
  }

  if (res) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  std::cout << std::endl;
  return 0;
}
