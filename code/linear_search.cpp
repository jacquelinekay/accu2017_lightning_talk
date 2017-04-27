#include <iostream>
#include <utility>

#ifndef BENCHMARK_SIZE  
#define BENCHMARK_SIZE 4
#endif

struct linear_match {
  template<size_t M>
  void apply() {
    if (index == M) {
      std::cout << M << "\n";
    }
  }

  template<size_t ...I>
  void apply_sequence(std::index_sequence<I...>&&) {
    (apply<I>(), ...);
  }

  const unsigned index;
};

int main(int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  const unsigned i = atoi(argv[1]);
  constexpr auto N = BENCHMARK_SIZE;

  if (i >= N) {
    return 255;
  }

  linear_match{i}.apply_sequence(std::make_index_sequence<N>{});

  return 0;
}
