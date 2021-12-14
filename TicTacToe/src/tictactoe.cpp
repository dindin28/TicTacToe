#include "tictactoe/tictactoe.h"

#include <iostream> // temporary

TicTacToe::TicTacToe()
  : turn_crosses_(true),
    array_({{' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '}}),
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
  outputter_.ShowBoard(array_, turn_crosses_);

  inputter_.StartThread();
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
      outputter_.StopCursorBlinking();
      inputter_.StopThread();
      inputter_.ClearKeys();
      inputter_.AddKey(VK_RETURN);
      inputter_.ChangeSignal(&TicTacToe::EndingHandler);
      inputter_.StartThread();
      outputter_.ClearScreen();
      outputter_.ShowStatistics();
      outputter_.ShowText(std::string("Press ENTER to quit\n"));
    }
    break;
    case(VK_RETURN):
    {
      // On pressing enter
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