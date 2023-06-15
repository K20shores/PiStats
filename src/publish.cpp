#include <iostream>

#include <pistats/stats.h>
#include <pistats/publish.h>

void publish_stats(const Stats& stats) {
  std::cout << "Number of CPUs: " << stats.cpu.ncpus << std::endl;
  std::cout << "CPU temperature: " << stats.cpu.cpu_temperature << std::endl;
  std::cout << "CPU 0 freq " << stats.cpu.cpu_frequency[0] <<  " MHz" << std::endl;
  std::cout << "CPU 1 freq " << stats.cpu.cpu_frequency[1] <<  " MHz" << std::endl;
  std::cout << "CPU 2 freq " << stats.cpu.cpu_frequency[2] <<  " MHz" << std::endl;
  std::cout << "CPU 3 freq " << stats.cpu.cpu_frequency[3] <<  " MHz" << std::endl;
  std::cout << "Total memory " << stats.memory.total_memory << std::endl;
  std::cout << "Used memory " << stats.memory.used_memory << std::endl;
}