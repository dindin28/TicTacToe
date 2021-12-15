#include "tictactoe/tictactoe.h"
#include "tictactoe/statistics.h"

#include <iostream> // temporary

TicTacToe::TicTacToe()
  : which_turn_('O'),
    array_({{' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}}),
    cursor_position_(COORD{0,0}),
    outputter_(array_),
    inputter_(&TicTacToe::GamingHandler, *this),
    end_of_game_(false)
{
  inputter_.AddKey(VK_LEFT);
  inputter_.AddKey(VK_RIGHT);
  inputter_.AddKey(VK_UP);
  inputter_.AddKey(VK_DOWN);
  inputter_.AddKey(VK_SPACE);
  inputter_.AddKey(VK_ESCAPE);
}

TicTacToe::~TicTacToe()
{
  while(end_of_game_ == false);
  inputter_.StopThread();
  outputter_.StopCursorBlinking();
}

void TicTacToe::StartGame()
{
  outputter_.SetCOORD(cursor_position_);
  outputter_.StartCursorBlinking();
  outputter_.ShowBoard(array_, which_turn_);

  inputter_.StartThread();
}

void TicTacToe::EndGame(char ch)
{
  // Inputter
  inputter_.StopThread();
  inputter_.AddKey(VK_RETURN);
  inputter_.ChangeSignal(&TicTacToe::EndingHandler);
  inputter_.StartThread();

  // Outputter
  Statisticks statisticks;
  statisticks.ReadFile();
  outputter_.StopCursorBlinking();
  outputter_.ClearScreen();
  switch (ch)
  {
    case('X'):
    {
      outputter_.ShowText(std::string("X is winner!!!\n\n"));
      statisticks.IncrementCrosses();
    }
    break;
    case('O'):
    {
      outputter_.ShowText(std::string("O is winner!!!\n\n"));
      statisticks.IncrementNoughts();
    }
    break;
    case(' '):
    {
      outputter_.ShowText(std::string("Draw\n\n"));
      statisticks.IncrementDraws();
    }
    break;
  }
  outputter_.ShowStatistics(statisticks);
  statisticks.UpdateFile();
  outputter_.ShowText(std::string("\nPress ENTER to quit\n"));
}

void TicTacToe::GamingHandler(int virtual_key)
{
  switch (virtual_key)
  {
    case(VK_LEFT):
    {
      cursor_position_.X--;
      if (cursor_position_.X < 0)
      {
        cursor_position_.X = array_[0].size() - 1;
      }
      outputter_.SetCOORD(cursor_position_);
    }
    break;
    case(VK_RIGHT):
    {
      cursor_position_.X++;
      if (cursor_position_.X >= array_[0].size())
      {
        cursor_position_.X = 0;
      }
      outputter_.SetCOORD(cursor_position_);
    }
    break;
    case(VK_UP):
    {
      cursor_position_.Y--;
      if (cursor_position_.Y < 0)
      {
        cursor_position_.Y = array_.size() - 1;
      }
      outputter_.SetCOORD(cursor_position_);
    }
    break;
    case(VK_DOWN):
    {
      cursor_position_.Y++;
      if (cursor_position_.Y >= array_.size())
      {
        cursor_position_.Y = 0;
      }
      outputter_.SetCOORD(cursor_position_);
    }
    break;
    case(VK_ESCAPE):
    {
      EndGame('\0');
    }
    break;
    case(VK_SPACE):
    {
      if (tictactoe_algorithms_.CheckPutToBoard(array_, cursor_position_))
      {
        array_[cursor_position_.Y][cursor_position_.X] = which_turn_;
        std::pair<bool, char> pair = tictactoe_algorithms_.CheckWin(array_, cursor_position_);
        if (pair.first)
        {
          EndGame(pair.second);
          break;
        }
        if (tictactoe_algorithms_.CheckPutPossibility(array_) == false)
        {
          EndGame(' ');
          break;
        }
        tictactoe_algorithms_.ExpandMatrix(array_);
        tictactoe_algorithms_.SwitchTurn(which_turn_);
        outputter_.ClearScreen();
        outputter_.ShowBoard(array_, which_turn_);
      }
    }
    break;
  }
}

void TicTacToe::EndingHandler(int virtual_key)
{
  if(virtual_key == VK_RETURN)
  {
    end_of_game_ = true;
  }
}