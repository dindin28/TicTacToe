#include "tictactoe/tictactoe.h"

#include <conio.h>

#include <iostream>

std::vector<std::vector<char>> array =
{
  {'X', 'O', 'O', 'X'},
  {'X', 'X', 'O', 'X'},
  {'O', 'X', 'O', 'X'},
};

int main()
{
  TicTacToe game;
  game.ShowBoard(array);

  std::cout << "Press any key" << std::endl;
  _getch();
  return 0;
}