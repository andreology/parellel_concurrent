//demonstration on daemon threads
//A process must wait until all daemon threads are done running
#include <thread>
#include <chrono>

void street_cleaner() {
  while(true) {
    printf("Street cleaner is cleaning street");
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  std::thread cleaning_vehicle(street_cleaner);
  //allow thread to run independently without needing joinable interface
  //otherwise the process would run infinetly
  cleaning_vehicle.detach();
  for(int i = 0; i < 3; i++) {
    printf("Pedestrians are parking...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  printf("Pedestrians are gone\n");
  //cleaning_vehicle.join();
}
