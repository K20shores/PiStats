#pragma once

#include <stddef.h> 
#include <vector>

struct CPU {
  size_t ncpus{};
  double cpu_temperature{}; // degrees
};

struct Stats {
  CPU cpu{};
};

Stats get_hardware_stats();