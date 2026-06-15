#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  int32_t n = 0;
  std::cin >> n;

  std::vector<std::vector<int32_t>> triangle(n);
  std::vector<std::vector<int32_t>> dp(n - 1);
  std::vector<std::vector<int32_t>> child_mat(n - 1);

  for (int32_t i = 0; i < n; ++i) {
    triangle[i].resize(i + 1);
    for (int32_t j = 0; j <= i; ++j) {
      std::cin >> triangle[i][j];
    }
  }

  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j <= i; ++j) {
      std::cout << triangle[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << std::endl;
  return 0;
}
