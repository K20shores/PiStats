#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include <pistats/stats.h>

double get_temperature(){
  std::filesystem::path path("/sys/class/thermal/thermal_zone0/temp");

  std::fstream file(path, std::ios_base::in);

  double temperature = 0;
  if (!file) {
    std::cerr << "Failed to open the temperature file\n";
  }
  else {
    std::string line;
    if (std::getline(file, line)) {
      // Convert from millidegrees to degrees
      temperature = std::stod(line) / 1000.0f;
    }
  }

  return temperature;
};

long double get_cpu_frequency(std::filesystem::path path) {
  std::fstream file(path, std::ios_base::in);

  long double freq = 0;
  if (!file) {
    std::cerr << "Failed to open the frequency file\n";
  }
  else {
    std::string line;
    if (std::getline(file, line)) {
      // Convert from millidegrees to degrees
      freq = std::stod(line) / 1e6;
    }
  }

  return freq;
}

std::vector<long double> get_all_cpu_frequencies() {
  std::filesystem::path cpu0_path("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu1_path("/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu2_path("/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu3_path("/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq");

  return std::vector<long double> {
    get_cpu_frequency(cpu0_path),
    get_cpu_frequency(cpu1_path),
    get_cpu_frequency(cpu2_path),
    get_cpu_frequency(cpu3_path)
  };
}

Stats get_hardware_stats() {
  Stats stats;
  stats.cpu.ncpus = std::thread::hardware_concurrency();
  stats.cpu.cpu_temperature = get_temperature();
  stats.cpu.cpu_frequency = get_all_cpu_frequencies();
  
  return stats;
}