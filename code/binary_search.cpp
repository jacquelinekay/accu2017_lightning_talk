#include <iostream>

#ifndef BENCHMARK_SIZE  
#define BENCHMARK_SIZE 4
#endif

struct binary_search_match {
  template<int M, int L, int R>
  void apply() {
    if (index == M) {
      std::cout << M << std::endl;
    } else if (index > M) {
      constexpr auto L2 = M + 1;
      this->apply<(L2 + R) / 2, L2, R>();
    } else if (index < M) {
      constexpr auto R2 = M - 1;
      this->apply<(L + R2) / 2, L, R2>();
    }
  }

  const unsigned index;
};

int main(int argc, char** argv) {
  if (argc < 2) {
    return 255;
  }
  const unsigned i = atoi(argv[1]);
  constexpr auto N = BENCHMARK_SIZE;

  static_assert(N > 0);
  if (i >= N) {
    return 255;
  }

  binary_search_match{i}.apply<(N - 1) / 2, 0, N - 1>();

  return 0;
}
