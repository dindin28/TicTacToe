#ifndef TICTACTOE_SRC_OUTPUTTER_H
#define TICTACTOE_SRC_OUTPUTTER_H

#include "tictactoe/statistics.h"

#include <windows.h>

#include <vector>
#include <chrono>

class Outputter
{
public:
  Outputter(std::vector<std::vector<char>>& array);

  void ShowBoard(const std::vector<std::vector<char>>& array,
                 char which_turn) const;
  void ShowStatistics(const Statisticks& statistick);
  void ClearScreen();
  void ShowText(const std::string& text);


  void SetCOORD(COORD cursor_position);

  void StartCursorBlinking();
  void StopCursorBlinking();

private:
  COORD COORDConvertor(const COORD& cursor_position) const;

private:
  HANDLE handler_;
  std::vector<std::vector<char>>& array_;
  COORD cursor_position_;

// Cursor Blinking
private:
  bool CheckDelay(std::chrono::time_point<std::chrono::steady_clock> prev);
  void BlinkingThread();
  std::atomic<bool> cursor_blinking_;
  bool cursor_blinked_;
};

#endif // header guard