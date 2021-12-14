#ifndef TICTACTOE_SRC_TICTACTOE_H
#define TICTACTOE_SRC_TICTACTOE_H

#include "outputter.h"
#include "inputter.h"

#include <windows.h>

#include <vector>

class TicTacToe
{
public:
  TicTacToe();
  ~TicTacToe();

  void StartGame();

  void GamingHandler(int virtual_key);
  void EndingHandler(int virtual_key);

private:
  bool turn_crosses_;
  std::vector<std::vector<char>> array_;
  Outputter outputter_;
  Inputter inputter_;
  COORD cursor_position_;

  bool end_of_game_;
};

#endif // Header guard