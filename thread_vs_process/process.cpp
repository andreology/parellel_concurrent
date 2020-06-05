/**
* A program to show execution scheduling coffee brewing
*/
#include <thread>
#include <chrono>

bool brew = true;

void brew_coffee(const char* coffeeType) {
  unsigned int coffeeCount = 0;
  while(brewing) {
    coffeeCount++;
  }
  printf("%s brewing %u coffee.\n", coffeeType, coffeeCount);
}

int main() {
  // threads start around the same time
  std::thread machine(brew_coffee, "colombian");
  std::thread machine0(brew_coffee, "pike place");
  //begin threads
  printf("colombian and pike place coffee beans are brewing! \n");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  brew = false;
  //stop gracefully
  machine.join();
  machine0.join();
}
