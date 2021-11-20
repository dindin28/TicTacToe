#ifndef TICTACTOE_SRC_TICTACTOE_H
#define TICTACTOE_SRC_TICTACTOE_H

#include "outputter.h"

#include <windows.h>

#include <vector>

class TicTacToe
{
public:
  TicTacToe();

  const Outputter& GetOutputter();
  void ShowBoard();

private:
  std::vector<std::vector<char>> array_;
  HANDLE handler_;
  Outputter outputter_;
};

#endif // header guard