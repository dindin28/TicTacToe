#ifndef TICTACTOE_SRC_INPUTTER_H
#define TICTACTOE_SRC_INPUTTER_H

#include <map>
#include <chrono>
#include <mutex>
#include <functional>

class TicTacToe;

class Inputter
{
 public:
  Inputter(std::function<void(TicTacToe&, int)> signal_pointer,
           TicTacToe& object);
  void AddKey(int virtual_key);
  void ClearKeys();

  void StartThread();
  void StopThread();

  void ChangeSignal(std::function<void(TicTacToe&, int)> signal_pointer);

 private:
  void ThreadFunction();
  bool CheckPressed(int virtual_key);
  bool CheckDelay(std::chrono::time_point<std::chrono::steady_clock> prev);
  bool thread_in_work_;

 private:
  std::map<int, std::chrono::time_point<std::chrono::steady_clock>> virtual_keys_;

  std::function<void(TicTacToe&, int)> signal_pointer_;
  TicTacToe& object_;
};

#endif // Header guard