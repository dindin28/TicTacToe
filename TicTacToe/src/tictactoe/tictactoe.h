#ifndef TICTACTOE_SRC_TICTACTOE_H
#define TICTACTOE_SRC_TICTACTOE_H

#include "outputter.h"
#include "inputter.h"
#include "tictactoe_algorithms.h"

#include <windows.h>

#include <vector>

class TicTacToe
{
public:
  TicTacToe();
  ~TicTacToe();

  void StartGame();
  void EndGame(char ch);

  void GamingHandler(int virtual_key);
  void EndingHandler(int virtual_key);

private:
  char which_turn_;
  std::vector<std::vector<char>> array_;
  Outputter outputter_;
  Inputter inputter_;
  TicTacToeAlgorithms tictactoe_algorithms_;

  COORD cursor_position_;

  bool end_of_game_;
};

#endif // Header guard