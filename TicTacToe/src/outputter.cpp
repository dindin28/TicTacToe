#include "tictactoe/outputter.h"

#include <format>
#include <iostream>

void Outputter::ShowBoard(const std::vector<std::vector<char>>& array_) const
{
  // Top row
  std::cout << char(201); // top left edge
  for (int i{}; i < array_[0].size(); ++i)
  {
    if (i != array_[0].size() - 1)
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
  for (int i{}; i < array_.size(); ++i)
  {
    std::cout << char(186); // vertical line
    for (int j{}; j < array_[0].size(); ++j)
    {
      std::cout << array_[i][j] << char(186);
    }
    std::cout << std::endl;
    if(i < array_.size() - 1)
    {
      std::cout << char(204); // vertical line with horizontal line
      if (i != array_.size() - 1)
      {
        for (int j{}; j < array_[0].size(); ++j)
        {
          if (j != array_[0].size() - 1)
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
  for (int i{}; i < array_[0].size(); ++i)
  {
    if (i != array_[0].size() - 1)
    {
      std::cout << char(205) << char(202);
    }
    else
    {
      std::cout << char(205);
    }
  }
  std::cout << char(188) << std::endl; // bottom right edge
}