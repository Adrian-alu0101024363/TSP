#include "../headers/Timer.h"

void Timer::finish() {
  if (start_ != -1) {
    finish_ = clock() - start_;
    convert();
  } else {
    std::cout << "Not started" << std::endl;
  }
}

void Timer::print(std::string timeOf) {
  std::cout << std::endl << "CPU time " << timeOf << ": " << cpuTime_ << " seconds" << std::endl;
}