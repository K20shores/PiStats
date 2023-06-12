
#include <pistats/stats.h>
#include <pistats/publish.h>

void publish_stats(const Stats& stats) {
  std::cout << "Number of CPUs: " << stats.cpu.ncpus << std::endl;
  std::cout << "CPU temperature: " << stats.cpu.cpu_temperature << std::endl;
}