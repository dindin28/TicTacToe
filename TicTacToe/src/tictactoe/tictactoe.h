#ifndef TICTACTOE_SRC_TICTACTOE_H
#define TICTACTOE_SRC_TICTACTOE_H

#include "outputter.h"

#include <windows.h>

#include <vector>

class TicTacToe
{
public:
  TicTacToe();

  void StartGame();

private:
  bool turn_crosses_;
  std::vector<std::vector<char>> array_;
  Outputter outputter_;
  COORD cursor_position_;
};

#endif // Header guard