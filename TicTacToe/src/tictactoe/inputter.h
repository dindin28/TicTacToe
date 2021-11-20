#ifndef TICTACTOE_SRC_INPUTTER_H
#define TICTACTOE_SRC_INPUTTER_H

#include <map>
#include <chrono>

class Inputter
{
 public:
  Inputter(void(*signal_pointer)(int));
  void AddKey(int virtual_key);
  void AssignSignal(void(*signal_pointer)(int));
  
 private:
  void ThreadFunction();
  bool CheckPressed(int virtual_key);
  bool CheckDelay(std::chrono::time_point<std::chrono::steady_clock> prev);
  void StartThread();

 private:
  std::map<int, std::chrono::time_point<std::chrono::steady_clock>> virtual_keys_;
  void(*signal_pointer_)(int);
};

#endif // header guard