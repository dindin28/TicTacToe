#include "outputter.h"

#include <format>
#include <iostream>

void Outputter::ShowBoard(std::vector<std::vector<char>> array_) const
{
  std::cout << std::format("{}{}{}{}{}\n", char(201), char(205), char(203), char(205), char(187));
  std::cout << std::format("{} {} {}\n", char(186), char(186), char(186));
  std::cout << std::format("{}{}{}{}{}\n", char(204), char(205), char(206), char(205), char(185));
  std::cout << std::format("{} {} {}\n", char(186), char(186), char(186));
  std::cout << std::format("{}{}{}{}{}\n", char(200), char(205), char(202), char(205), char(188));
}