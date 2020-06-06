//Demo on fixing data race error with a mutex
//where two machines(threads) are attempting to
//read same location in memory
#include <thread>
#include <mutex>
#include <chrono>

unsigned int locationin_memory = 0;
std::mutex mutex_fix;
//problem: read -> modify -> write
//threads interrupt write for each other
void compute() {
  //one thread hold mutex

  for(int i = 0; i < 5; i++) {
    printf("current %d thread is working... \n", std::this_thread::get_id());
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //critical section should hold the mutex where all the heavy lifting is done
    mutex_fix.lock();
    locationin_memory++;
    mutex_fix.unlock();
  }
  //same thread should let go of mutex

}

int main() {
  std::thread machine(compute);
  std::thread machine0(compute);

  machine.join();
  machine0.join();
  printf("Computed variable %u \n", locationin_memory);
}
