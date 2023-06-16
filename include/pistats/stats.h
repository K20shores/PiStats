#pragma once

#include <filesystem>
#include <stddef.h> 
#include <string>
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
    std::string time;

    Stats();

private:
    double get_temperature() const;
    long double get_cpu_frequency(const std::filesystem::path& path) const;
    std::vector<long double> get_all_cpu_frequencies() const;
    Memory get_memory() const;
    std::string get_time() const;
};


Stats get_hardware_stats();