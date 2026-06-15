#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  int32_t n = 0;
  std::cin >> n;

  std::vector<std::vector<int32_t>> triangle(n);
  std::vector<std::vector<int32_t>> dp(n);
  std::vector<std::vector<int32_t>> child_mat(n - 1,
                                              std::vector<int32_t>(n - 1));

  for (int32_t i = 0; i < n; ++i) {
    triangle[i].resize(i + 1);
    for (int32_t j = 0; j <= i; ++j) {
      std::cin >> triangle[i][j];
    }
  }

  dp = triangle;

  for (int32_t i = n - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i + 1][j] <= dp[i + 1][j + 1]) {
        dp[i][j] += dp[i + 1][j];
        child_mat[i][j] = j;
      } else {
        dp[i][j] += dp[i + 1][j + 1];
        child_mat[i][j] = j + 1;
      }
    }
  }

  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j <= i; ++j) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << std::endl;
  return 0;
}
