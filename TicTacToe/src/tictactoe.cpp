#include "tictactoe/tictactoe.h"

TicTacToe::TicTacToe()
  : turn_crosses_(true),
    array_({{' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '},}),
    cursor_position_(COORD{0,0}),
    outputter_(array_)
{}

void TicTacToe::StartGame()
{
  outputter_.SetCOORD(cursor_position_);
  outputter_.StartCursorBlinking();
  outputter_.ShowBoard(array_, turn_crosses_);
}