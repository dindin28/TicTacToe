#include "tictactoe/tictactoe_algorithms.h"

#include "tictactoe/options.h"

#include <algorithm>

bool TicTacToeAlgorithms::CheckPutToBoard(const std::vector<std::vector<char>>& array,
                                          COORD coord) const
{
  if (array[coord.Y][coord.X] == ' ')
  {
    return true;
  }
  return false;
}

void TicTacToeAlgorithms::SwitchTurn(char& turn)
{
  if (turn == 'X')
  {
    turn = 'O';
  }
  else
  {
    turn = 'X';
  }
}

std::pair<bool, char> TicTacToeAlgorithms::CheckWin(const std::vector<std::vector<char>>& array,
                                                    COORD coord) const
{
  char fixed_char = array[coord.Y][coord.X];
  
  bool is_win = false;

  // Top
  if (is_win == false)
  {
    for (int i = coord.Y - 1, sum = 2; i >= 0; --i, ++sum)
    {
      if (fixed_char != array[i][coord.X])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }

  // Down
  if (is_win == false)
  {
    for (int i = coord.Y + 1, sum = 2; i < array.size(); ++i, ++sum)
    {
      if (fixed_char != array[i][coord.X])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }

  // Left
  if (is_win == false)
  {
    for (int i = coord.X - 1, sum = 2; i >= 0; --i, ++sum)
    {
      if (fixed_char != array[coord.Y][i])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }

  // Right
  if (is_win == false)
  {
    for (int i = coord.X + 1, sum = 2; i < array[0].size(); ++i, ++sum)
    {
      if (fixed_char != array[coord.Y][i])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }

  // Top-Left
  if (is_win == false)
  {
    for (int i = coord.Y - 1, j = coord.X - 1, sum = 2; i >= 0 && j >= 0; --i, --j, ++sum)
    {
      if (fixed_char != array[i][j])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }
  // Top-Right
  if (is_win == false)
  {
    for (int i = coord.Y - 1, j = coord.X + 1, sum = 2; i >= 0 && j < array[0].size(); --i, ++j, ++sum)
    {
      if (fixed_char != array[i][j])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }
  // Down-Left
  if (is_win == false)
  {
    for (int i = coord.Y + 1, j = coord.X - 1, sum = 2; i < array.size() && j >= 0; ++i, --j, ++sum)
    {
      if (fixed_char != array[i][j])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }
  // Down-Right
  if (is_win == false)
  {
    for (int i = coord.Y + 1, j = coord.X + 1, sum = 2; i < array.size() && j < array[0].size(); ++i, ++j, ++sum)
    {
      if (fixed_char != array[i][j])
      {
        break;
      }
      if (sum == kCountToWin)
      {
        is_win = true;
        break;
      }
    }
  }
  
  return std::make_pair(is_win, fixed_char);
}

bool TicTacToeAlgorithms::CheckPutPossibility(const std::vector<std::vector<char>>& array)
{
  bool return_value = false;

  for(const auto& rows : array)
  {
    for (const auto& iter : rows)
    {
      if(iter == ' ')
      {
        return_value = true;
        break;
      }
    }
  }
  return return_value;
}

void TicTacToeAlgorithms::ExpandMatrix(std::vector<std::vector<char>>& array)
{
  if (CheckRightBorder(array))
  {
    ExpandMatrixRight(array);
  }
  if (CheckLeftBorder(array))
  {
    ExpandMatrixLeft(array);
  }
  if (CheckTopBorder(array))
  {
    ExpandMatrixTop(array);
  }
  if (CheckDownBorder(array))
  {
    ExpandMatrixDown(array);
  }
}

void TicTacToeAlgorithms::ExpandMatrixRight(std::vector<std::vector<char>>& array)
{
  if (kMaxBoardWidth > array[0].size())
  {
    for (auto& iter : array)
    {
      iter.push_back(' ');
    }
  }
}

void TicTacToeAlgorithms::ExpandMatrixLeft(std::vector<std::vector<char>>& array)
{
  if (kMaxBoardWidth > array[0].size())
  {
    for (auto& iter : array)
    {
      iter.insert(iter.begin(), ' ');
    }
  }
}

void TicTacToeAlgorithms::ExpandMatrixTop(std::vector<std::vector<char>>& array)
{
  if (kMaxBoardWidth > array.size())
  {
    std::vector<char> new_vector(array[0].size());
    std::fill(new_vector.begin(), new_vector.end(), ' ');
    array.insert(array.begin(), new_vector);
  }
}

void TicTacToeAlgorithms::ExpandMatrixDown(std::vector<std::vector<char>>& array)
{
  if (kMaxBoardWidth > array.size())
  {
    std::vector<char> new_vector(array[0].size());
    std::fill(new_vector.begin(), new_vector.end(), ' ');
    array.push_back(new_vector);
  }
}

bool TicTacToeAlgorithms::CheckRightBorder(const std::vector<std::vector<char>>& array) const
{
  bool return_value = false;
  //Check right border
  for (int i = 0; i < array.size(); i++)
  {
    if (array[i][array[0].size() - 1] != ' ')
    {
      return_value = true;
      break;
    }
  }
  return return_value;
}

bool TicTacToeAlgorithms::CheckLeftBorder(const std::vector<std::vector<char>>& array) const
{
  bool return_value = false;
  //Check right border
  for (int i = 0; i < array.size(); i++)
  {
    if (array[i][0] != ' ')
    {
      return_value = true;
      break;
    }
  }
  return return_value;
}

bool TicTacToeAlgorithms::CheckTopBorder(const std::vector<std::vector<char>>& array) const
{
  bool return_value = false;
  //Check right border
  for (int i = 0; i < array[0].size(); i++)
  {
    if (array[0][i] != ' ')
    {
      return_value = true;
      break;
    }
  }
  return return_value;
}

bool TicTacToeAlgorithms::CheckDownBorder(const std::vector<std::vector<char>>& array) const
{
  bool return_value = false;
  //Check right border
  for (int i = 0; i < array[0].size(); i++)
  {
    if (array[array.size() - 1][i] != ' ')
    {
      return_value = true;
      break;
    }
  }
  return return_value;
}