#ifndef TICTACTOE_SRC_OUTPUTTER_H
#define TICTACTOE_SRC_OUTPUTTER_H

#include <vector>

class Outputter
{
public:
  void ShowBoard(std::vector<std::vector<char>> array_) const;
};

#endif // header guard