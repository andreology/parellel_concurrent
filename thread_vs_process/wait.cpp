// two machines working
#include <thread>
#include <chrono>

void machine_work_inprogress() {
  printf("Machine 0 is working and making for info\n" );
  std::this_thread::sleep_for(std::chrono::seconds(3));
  printf("Machine 0 is done waiting and working");
}

int main() {
  printf("Machine 1 tells Machine 0 to create info\n");
  std::thread machine0(machine_work_inprogress);

  printf("Machine 1 continues to work now without info\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));

  printf("Machine 1 waits for Machine 0 to finish making info\n");
  machine0.join();

  printf("Machines are both done\n");
}
