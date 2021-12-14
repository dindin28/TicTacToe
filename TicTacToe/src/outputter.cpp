#include "tictactoe/outputter.h"
#include "tictactoe/options.h"
#include "tictactoe/statistics.h"

#include <iostream>
#include <sstream>
#include <thread>

Outputter::Outputter(std::vector<std::vector<char>>& array)
  : handler_(GetStdHandle(STD_OUTPUT_HANDLE)),
    cursor_blinking_(false),
    cursor_blinked_(false),
    array_(array),
    cursor_position_(COORD{0, 0})
{
  const _CONSOLE_CURSOR_INFO* cursor_info = new _CONSOLE_CURSOR_INFO{100, FALSE};
  SetConsoleCursorInfo(handler_, cursor_info);
  delete cursor_info;
  SetConsoleTitle(L"TicTacToe");
}

COORD Outputter::COORDConvertor(const COORD& cursor_position) const
{
  COORD coord{ cursor_position };
  coord.X = coord.X * 2 + 1;
  coord.Y = coord.Y * 2 + 1;

  return coord;
}

void Outputter::ShowStatistics()
{
  Statisticks statisticks;
  statisticks.ReadFile();

  std::stringstream stream;
  stream << "O: " << statisticks.GetNoughts() << std::endl;
  stream << "X: " << statisticks.GetCrosses() << std::endl;
  stream << "Draws: " << statisticks.GetDraws() << std::endl;
  std::cout << stream.str();
}

void Outputter::ShowText(const std::string& text)
{
  std::cout << text;
}

void Outputter::ClearScreen()
{
  system("cls");
}

void Outputter::ShowBoard(const std::vector<std::vector<char>>& array,
                          bool turn_crosses) const
{
  // Top row
  std::cout << char(201); // top left edge
  for (int i{}; i < array[0].size(); ++i)
  {
    if (i != array[0].size() - 1)
    {
      std::cout << char(205) << char(203);
    }
    else
    {
      std::cout << char(205);
    }
  }
  std::cout << char(187) << std::endl; // top right edge

  // Cells with rows
  for (int i{}; i < array.size(); ++i)
  {
    std::cout << char(186); // vertical line
    for (int j{}; j < array[0].size(); ++j)
    {
      std::cout << array[i][j] << char(186);
    }
    std::cout << std::endl;
    if(i < array.size() - 1)
    {
      std::cout << char(204); // vertical line with horizontal line
      if (i != array.size() - 1)
      {
        for (int j{}; j < array[0].size(); ++j)
        {
          if (j != array[0].size() - 1)
          {
            std::cout << char(205) << char(206);
          }
          else
          {
            std::cout << char(205) << char(185) << std::endl;
          }
        }
      }
    }
  }

  // Bottom row
  std::cout << char(200); // bottom left edge
  for (int i{}; i < array[0].size(); ++i)
  {
    if (i != array[0].size() - 1)
    {
      std::cout << char(205) << char(202);
    }
    else
    {
      std::cout << char(205);
    }
  }
  std::cout << char(188) << std::endl; // bottom right edge

  std::stringstream string_stream;
  string_stream << "Turn: ";
  if (turn_crosses)
  {
    string_stream << "X\n";
  }
  else
  {
    string_stream << "O\n";
  }
  std::cout << string_stream.str();
}

void Outputter::SetCOORD(COORD cursor_position)
{
  cursor_position_ = COORDConvertor(cursor_position);
  SetConsoleCursorPosition(handler_, cursor_position);

  LPDWORD buff = new DWORD;
  WORD* background_color;
  background_color = new WORD(0x0000);
  for (short i = 0; i < array_.size(); ++i)
  {
    for (short j = 0; j < array_[0].size(); ++j)
    {
      if(cursor_position_.X != j || cursor_position_.Y != i)
      {
        WriteConsoleOutputAttribute(handler_, background_color, 1, COORDConvertor(COORD{ j, i }), buff);
      } 
    }
  }
  *background_color = WORD(0x0070);
  WriteConsoleOutputAttribute(handler_, background_color, 1, cursor_position_, buff);
  delete background_color;
  delete buff;
}

//===================
// Cursor Blinking
//===================

void Outputter::StartCursorBlinking()
{
  cursor_blinking_ = true;
  std::thread(&Outputter::BlinkingThread, this).detach();
}
void Outputter::StopCursorBlinking()
{
  cursor_blinking_ = false;
  LPDWORD buff = new DWORD;
  WORD* background_color;
  background_color = new WORD(0x0000);
  for (short i = 0; i < array_.size(); ++i)
  {
    for (short j = 0; j < array_[0].size(); ++j)
    {
      WriteConsoleOutputAttribute(handler_, background_color, 1, COORDConvertor(COORD{ j, i }), buff);
    }
  }
  delete background_color;
  delete buff;
}

bool Outputter::CheckDelay(std::chrono::time_point<std::chrono::steady_clock> prev)
{
  if (std::chrono::steady_clock::now() - prev > kCursorBlinkingDelay)
  {
    return true;
  }
  return false;
}

void Outputter::BlinkingThread()
{
  auto time_point = std::chrono::steady_clock::now();
  while (cursor_blinking_)
  {
    if (CheckDelay(time_point))
    {
      LPDWORD buff = new DWORD;
      const WORD* background_color;
      if (cursor_blinked_)
      {
        background_color = new WORD(0x0000);
      }
      else
      {
        background_color = new WORD(0x0070);
      }
      WriteConsoleOutputAttribute(handler_, background_color, 1, cursor_position_, buff);
      delete background_color;
      delete buff;
      cursor_blinked_ = !cursor_blinked_;
      time_point = std::chrono::steady_clock::now();
    }
  }
}