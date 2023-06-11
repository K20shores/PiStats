#include <iostream>

#include <pistats/stats.h>

int main(){
  Stats stats = get_hardware_stats();
  std::cout << "Number of CPUs: " << stats.cpu.ncpus << std::endl;
  std::cout << "CPU temperature: " << stats.cpu.cpu_temperature << std::endl;
}