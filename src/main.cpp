#include <pistats/publish.h>
#include <pistats/stats.h>

int main(){
  Stats stats = get_hardware_stats();
  publish_stats(stats);
}