#include "tictactoe/inputter.h"

// Local headers
#include "tictactoe/options.h"

// C headers
#include <windows.h>

// C++ headers
#include <thread>

//===========================
// Public functions
//===========================

Inputter::Inputter(std::function<void(TicTacToe&, int)> signal_pointer,
                   TicTacToe& object)
  : signal_pointer_(signal_pointer),
    object_(object),
    thread_in_work_(false)
{}

void Inputter::AddKey(int virtual_key)
{
  virtual_keys_.insert_or_assign(virtual_key, std::chrono::steady_clock::now());
}

void Inputter::ChangeSignal(std::function<void(TicTacToe&, int)> signal_pointer)
{
  signal_pointer_ = signal_pointer;
}

//===========================
// Private functions
//===========================

void Inputter::StartThread()
{
  thread_in_work_ = true;
  std::thread(&Inputter::ThreadFunction, this).detach();
}

void Inputter::StopThread()
{
  thread_in_work_ = false;
}

bool Inputter::CheckPressed(int virtual_key)
{
  if (GetKeyState(virtual_key) == -127 || GetKeyState(virtual_key) == -128)
  {
    return true;
  }
  return false;
}

bool Inputter::CheckDelay(std::chrono::time_point<std::chrono::steady_clock> prev)
{
  if(std::chrono::steady_clock::now() - prev > kKeyDelay)
  {
    return true;
  }
  return false;
}

void Inputter::ThreadFunction()
{
  while(thread_in_work_)
  {
    for (auto& [virtual_key, time_point] : virtual_keys_)
    {
      if (CheckDelay(time_point) && CheckPressed(virtual_key))
      {
        signal_pointer_(object_, virtual_key);         // Emit signal
        time_point = std::chrono::steady_clock::now(); // Reset timer
      }
    }
  }
}