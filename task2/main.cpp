#include <iostream>
#include <vector>
#include <cstdint>

void dfs(int64_t s, std::vector<std::vector<int64_t>>& adj, std::vector<bool>& visited) {
  visited[s] = true;
  for (int64_t u : adj[s]) {
    if (!visited[u]) {
      dfs(u, adj, visited);
    }
  }
}

int main() {
  int64_t n = 0;
  int64_t m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int64_t>> adj(n + 1);

  for (int64_t i = 0; i < m; ++i) {
    int64_t u = 0;
    int64_t v = 0;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<bool> visited(n + 1, false);
  int64_t count = 0;

  for (int64_t i = 1; i <= n; ++i) {
    if (!visited[i]) {
      count++;
      dfs(i, adj, visited);
    }
  }

  std::cout << count - 1 << std::endl;

  return 0;
}
