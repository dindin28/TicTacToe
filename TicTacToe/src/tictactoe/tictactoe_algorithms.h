#ifndef TICTACTOE_SRC_TICTACTOE_ALGORITHMS_H
#define TICTACTOE_SRC_TICTACTOE_ALGORITHMS_H

#include <windows.h>

#include <vector>

class TicTacToeAlgorithms
{
public:
  // Read-only functions
  bool CheckPutToBoard(const std::vector<std::vector<char>>& array, COORD coord) const;
  std::pair<bool, char> CheckWin(const std::vector<std::vector<char>>& array, COORD coord) const;
  bool CheckPutPossibility(const std::vector<std::vector<char>>& array);

  // Writable functions
  void SwitchTurn(char& turn);
  void ExpandMatrix(std::vector<std::vector<char>>& array);

private:
  void ExpandMatrixRight(std::vector<std::vector<char>>& array);
  void ExpandMatrixLeft(std::vector<std::vector<char>>& array);
  void ExpandMatrixTop(std::vector<std::vector<char>>& array);
  void ExpandMatrixDown(std::vector<std::vector<char>>& array);

private:
  bool CheckRightBorder(const std::vector<std::vector<char>>& array) const;
  bool CheckLeftBorder(const std::vector<std::vector<char>>& array) const;
  bool CheckTopBorder(const std::vector<std::vector<char>>& array) const;
  bool CheckDownBorder(const std::vector<std::vector<char>>& array) const;
};

#endif // Header guard