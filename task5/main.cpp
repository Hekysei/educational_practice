#include <iostream>
#include <cstdint>

int main() {
  int64_t h = 0;
  int64_t w = 0;
  std::cin >> h >> w;

  int64_t min_r = h;
  int64_t max_r = -1;
  int64_t min_c = w;
  int64_t max_c = -1;

  int64_t val = 0;
  for (int64_t r = 0; r < h; ++r) {
    for (int64_t c = 0; c < w; ++c) {
      std::cin >> val;
      if (val == 1) {
        if (r < min_r)
          min_r = r;
        if (r > max_r)
          max_r = r;
        if (c < min_c)
          min_c = c;
        if (c > max_c)
          max_c = c;
      }
    }
  }

  std::cout << min_r - 1 << " " << min_c - 1 << " " << max_r + 1 << " " << max_c + 1 << std::endl;

  return 0;
}
