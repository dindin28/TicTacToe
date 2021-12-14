#include "tictactoe/tictactoe.h"

#include <conio.h>

#include <iostream>

int main()
{
  TicTacToe game;
  game.StartGame();

  std::cout << "Press any key" << std::endl;
  _getch();
  return 0;
}