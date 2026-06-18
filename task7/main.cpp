#include <iostream>
#include <cstdint>

int main() {
  while (1) {
    char c;
    std::cin >> c;
    std::cout << c + 0 << " ";
    if (c >= 48 && c <= 57) {
      std::cout << "num";
    }
    if (c >= 65 && c <= 90) {
      std::cout << "LET";
    }
    std::cout << "\n";
  }
  return 0;
}
