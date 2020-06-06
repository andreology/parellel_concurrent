//Demo on solution to data race error with atomic for simple smaller computations
//where two machines(threads) are attempting to
//read same location in memory
#include <thread>
#include <atomic>

std::atomic<unsigned int> locationin_memory(0);
//problem: read -> modify -> write
//threads interrupt write for each other
void compute() {
  for(int i = 0; i < 10000000; i++) {
    locationin_memory++;
  }
}

int main() {
  std::thread machine(compute);
  std::thread machine0(compute);

  machine.join();
  machine0.join();
  printf("Computed variable %u \n", locationin_memory.load());
}
