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

    int64_t b_1 = std::min(b, x);
    res += b_1;
    x -= b_1;

    int64_t a_12 = std::min(a, x+y);
    res += a_12;

    std::cout << res << " ";
  }

  std::cout << std::endl;
  return 0;
}
