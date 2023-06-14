#pragma once

#include <stddef.h> 

struct CPU {
  size_t ncpus{};
  double cpu_temperature{}; // degrees C
};

struct Stats {
  CPU cpu{};
};

Stats get_hardware_stats();