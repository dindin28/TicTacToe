#include "tictactoe.h"

TicTacToe::TicTacToe()
{
  SetConsoleTitle(L"TicTacToe");
  //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
  handler_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

const Outputter& TicTacToe::GetOutputter()
{
  return outputter_;
}

void TicTacToe::ShowBoard()
{
  outputter_.ShowBoard(array_);
}