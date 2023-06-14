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

struct Stats {
  CPU cpu{};
};

Stats get_hardware_stats();