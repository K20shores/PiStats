#pragma once

#include <stddef.h> 
#include <vector>

struct CPU {
  size_t ncpus{};
  // degrees C
  double cpu_temperature{};
  // MHz
  std::vector<long double> cpu_frequency{};
};

struct Memory {
    // read from a file
    unsigned long total_memory{};
    unsigned long free_memory{};
    unsigned long available_memory{};
    unsigned long buffered_memory{};
    unsigned long cached_memory{};
    // computed
    unsigned long used_memory{};
};

struct Stats {
  CPU cpu{};
  Memory memory{};
};

Stats get_hardware_stats();