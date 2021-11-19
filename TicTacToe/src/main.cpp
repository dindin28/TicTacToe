#include "tictactoe.h"

#include <conio.h>

#include <iostream>

std::vector<std::vector<char>> array =
{
  {'X', 'O', 'O'},
  {'X', 'X', 'O'},
  {'O', 'X', 'O'},
};

int main()
{
  TicTacToe game;
  game.ShowBoard();

  std::cout << "Press any key" << std::endl;
  _getch();
  return 0;
}