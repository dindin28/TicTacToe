#include "tictactoe/statistics.h"

#include "tictactoe/options.h"

#include <fstream>
#include <regex>
#include <string>
#include <iostream> // Temporary include

Statisticks::Statisticks()
  : file_readed_(false), noughts_(0), crosses_(0), draws_(0)
{}

bool Statisticks::ReadFile()
{
  bool return_value = true;

  std::ifstream file_handler(statistics_file.data());

  if (file_handler.is_open() == false)
  {
    return_value = false;
  }

  std::string file_data;
  if(return_value)
  {
    file_data = std::string(std::istreambuf_iterator<char>(file_handler),
                            std::istreambuf_iterator<char>());
  }

  if(return_value)
  {
    std::regex base_regex;
    std::smatch base_match;

    // Read noughts
    base_regex = ("noughts ([0-9]+)");
    if (std::regex_search(file_data, base_match, base_regex))
    { noughts_ = std::stoul(base_match[1]); }
    else
    { return_value = false; }

    // Read crosses
    base_regex = ("crosses ([0-9]+)");
    if (std::regex_search(file_data, base_match, base_regex))
    { crosses_ = std::stoul(base_match[1]); }
    else
    { return_value = false; }

    // Read draws
    base_regex = ("draws ([0-9]+)");
    if (std::regex_search(file_data, base_match, base_regex))
    { draws_ = std::stoul(base_match[1]); }
    else
    { return_value = false; }
  }

  if (return_value)
  {
    file_readed_ = true;
  }

  return return_value;
}

bool Statisticks::UpdateFile()
{
  bool return_value;
  if (file_readed_)
  { return_value = true; }
  else
  { return_value = false; }

  std::ofstream file_handler(statistics_file.data());

  if (file_handler.is_open() == false)
  {
    return_value = false;
  }

  std::stringstream common_string;
  if(return_value)
  {
    common_string << "noughts " << noughts_ << "\n";
    common_string << "crosses " << crosses_ << "\n";
    common_string << "draws " << draws_;
    file_handler << common_string.rdbuf();
  }

  return return_value;
}

void Statisticks::IncrementNoughts() { if(file_readed_) ++noughts_; }
void Statisticks::IncrementCrosses() { if (file_readed_) ++crosses_; }
void Statisticks::IncrementDraws() { if (file_readed_) ++draws_; }

const unsigned int Statisticks::GetNoughts() const { return noughts_; }
const unsigned int Statisticks::GetCrosses() const { return crosses_; }
const unsigned int Statisticks::GetDraws() const { return draws_; }