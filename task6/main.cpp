#include <iostream>
#include <algorithm>
#include <cstdint>

int main() {
  int64_t n = 0;
  std::cin >> n;
  for (int64_t i = 0; i < n; ++i) {
    int64_t a, b, x, y;
    std::cin >> a >> b >> x >> y;

    int64_t res = 0;

    res += std::min({b + a, x + a, x + y});

    std::cout << res << " ";
  }

  std::cout << std::endl;
  return 0;
}
