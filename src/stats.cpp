#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include <pistats/stats.h>

double Stats::get_temperature() const
{
  std::filesystem::path path("/sys/class/thermal/thermal_zone0/temp");

  std::fstream file(path, std::ios_base::in);

  double temperature = 0;
  if (!file)
  {
    std::cerr << "Failed to open the temperature file\n";
  }
  else
  {
    std::string line;
    if (std::getline(file, line))
    {
      // Convert from millidegrees to degrees
      temperature = std::stod(line) / 1000.0f;
    }
    file.close();
  }

  return temperature;
};

long double Stats::get_cpu_frequency(const std::filesystem::path& path) const
{
  std::fstream file(path, std::ios_base::in);

  long double freq = 0;
  if (!file)
  {
    std::cerr << "Failed to open the frequency file\n";
  }
  else
  {
    std::string line;
    if (std::getline(file, line))
    {
      freq = std::stod(line) / 1e6;
    }
    file.close();
  }

  return freq;
}

std::vector<long double> Stats::get_all_cpu_frequencies() const
{
  std::filesystem::path cpu0_path("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu1_path("/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu2_path("/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq");
  std::filesystem::path cpu3_path("/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq");

  return std::vector<long double>{
      {get_cpu_frequency(cpu0_path)},
      {get_cpu_frequency(cpu1_path)},
      {get_cpu_frequency(cpu2_path)},
      {get_cpu_frequency(cpu3_path)}
    };
}

Memory Stats::get_memory() const
{
  std::filesystem::path path("/proc/meminfo");
  std::fstream file(path, std::ios_base::in);

  Memory mem;

  if (!file.is_open())
  {
    std::cerr << "Failed to open /proc/meminfo" << std::endl;
  }
  else
  {
    std::string line;
    while (std::getline(file, line))
    {
      if (line.compare(0, 9, "MemTotal:") == 0){
        mem.total_memory = std::stoul(line.substr(10));
      }
      else if (line.compare(0, 8, "MemFree:") == 0){
        mem.free_memory = std::stoul(line.substr(9));
      }
      else if (line.compare(0, 15, "MemAvailable:") == 0){
        mem.available_memory = std::stoul(line.substr(16));
      }
      else if (line.compare(0, 8, "Buffers:") == 0){
        mem.buffered_memory = std::stoul(line.substr(8));
      }
      else if (line.compare(0, 7, "Cached:") == 0){
        mem.cached_memory = std::stoul(line.substr(7));
      }
    }

    file.close();


    // Memory Used = MemTotal - MemFree - MemBuffers - MemCached
    mem.used_memory = mem.total_memory - mem.free_memory - mem.buffered_memory - mem.cached_memory;
  }

  return mem;
}

std::string Stats::get_time() const
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

Stats::Stats()
{
    cpu.ncpus = std::thread::hardware_concurrency();
    cpu.cpu_temperature = get_temperature();
    cpu.cpu_frequency = get_all_cpu_frequencies();
    memory = get_memory();
    time = get_time();
}