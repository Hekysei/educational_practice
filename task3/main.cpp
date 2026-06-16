#include <iostream>
#include <cstdint>
#include <vector>

class SegmentTree {
 public:
  explicit SegmentTree(int64_t n) : size_(n) {
    int64_t mult = 1;
    while (mult < n) {
      mult *= 2;
    }
    buffer_.assign(mult * 2 - 1, 0);
  }

  void add(int64_t index, int64_t value) {
    add(0, 0, size_ - 1, index, value);
  }

  int64_t query(int64_t left, int64_t right) const {
    return query(0, 0, size_ - 1, left, right);
  }

 private:
  void add(int64_t node, int64_t left, int64_t right, int64_t index, int64_t value) {
    if (left == right) {
      buffer_[node] += value;
      return;
    }

    int64_t mid = left + (right - left) / 2;
    if (index <= mid) {
      add(2 * node + 1, left, mid, index, value);
    } else {
      add(2 * node + 2, mid + 1, right, index, value);
    }

    buffer_[node] = buffer_[2 * node + 1] + buffer_[2 * node + 2];
  }

  int64_t query(int64_t node, int64_t left, int64_t right, int64_t query_left, int64_t query_right) const {
    if (query_left > right || query_right < left) {
      return 0;
    }

    if (query_left <= left && right <= query_right) {
      return buffer_[node];
    }

    int64_t mid = left + (right - left) / 2;
    int64_t left_sum = query(2 * node + 1, left, mid, query_left, query_right);
    int64_t right_sum = query(2 * node + 2, mid + 1, right, query_left, query_right);

    return left_sum + right_sum;
  }

  int64_t size_;
  std::vector<int64_t> buffer_;
};

int main() {
  int64_t n = 0;
  int64_t k = 0;

  std::cin >> n >> k;

  SegmentTree st(n);

  for (int64_t i = 0; i < k; ++i) {
    int64_t type = 0;
    std::cin >> type;

    if (type == 1) {
      int64_t index = 0;
      int64_t x = 0;
      std::cin >> index >> x;
      st.add(index - 1, x);
    } else if (type == 2) {
      int64_t u = 0;
      int64_t r = 0;
      std::cin >> u >> r;
      std::cout << st.query(u - 1, r - 1) << std::endl;
    }
  }

  return 0;
}
