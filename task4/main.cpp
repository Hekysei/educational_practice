#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

int main() {
  int64_t n = 0;
  int64_t k = 0;
  std::cin >> n >> k;

  std::vector<int64_t> p(n);
  for (int64_t i = 0; i < n; ++i) {
    std::cin >> p[i];
    p[i]--;
  }

  std::string s_final;
  std::string s_init(n, ' ');
  std::vector<bool> visited(n, false);

  std::cin >> s_final;

  for (int64_t i = 0; i < n; ++i) {
    if (!visited[i]) {
      std::vector<int64_t> cycle;
      int64_t curr = i;

      while (!visited[curr]) {
        visited[curr] = true;
        cycle.push_back(curr);
        curr = p[curr];
      }

      for (auto el : cycle) {
        std::cout << el << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}
