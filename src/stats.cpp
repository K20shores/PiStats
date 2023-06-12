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

Stats get_hardware_stats() {
  Stats stats;
  stats.cpu.ncpus = std::thread::hardware_concurrency();
  stats.cpu.cpu_temperature = get_temperature();
  
  return stats;
}