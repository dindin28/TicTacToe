#include "tictactoe/tictactoe.h"
#include "tictactoe/inputter.h"
#include "tictactoe/statistics.h"

#include <conio.h>
#include <windows.h>

#include <iostream>

std::vector<std::vector<char>> array =
{
  {'X', 'O', 'O'},
  {'X', 'X', 'O'},
  {'O', 'X', 'O'},
};

void Slot(int virtual_key)
{
  switch(virtual_key)
  {
    case(VK_UP):
      std::cout << "Arrow up pressed\n";
      break;
    case(VK_DOWN):
      std::cout << "Arrow down pressed\n";
      break;
    case(VK_LEFT):
      std::cout << "Arrow left pressed\n";
      break;
    case(VK_RIGHT):
      std::cout << "Arrow right pressed\n";
      break;
  }
}

int main()
{
  TicTacToe game;
  game.ShowBoard();

  Statisticks statisticks;
  statisticks.ReadFile();
  statisticks.IncrementCrosses();
  statisticks.UpdateFile();

  //while(true);
  //{ std::cout << "Waiting slot\n"; }
  std::cout << "Press any key" << std::endl;
  _getch();
  return 0;
}