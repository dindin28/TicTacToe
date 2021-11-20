#ifndef TICTACTOE_SRC_OPTIONS_H
#define TICTACTOE_SRC_OPTIONS_H

#include <chrono>
#include <string_view>

// Inputter class
constexpr std::chrono::duration<long double> key_delay
  = std::chrono::milliseconds(250);

// Statistics class
constexpr std::string_view statistics_file("resources/statistics.txt");

#endif // header guard