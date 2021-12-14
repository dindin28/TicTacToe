#ifndef TICTACTOE_SRC_OPTIONS_H
#define TICTACTOE_SRC_OPTIONS_H

#include <chrono>
#include <string_view>

// Inputter class
constexpr std::chrono::duration<long double> kKeyDelay
  = std::chrono::milliseconds(250);

// Statistics class
constexpr std::string_view kStatisticsFile("resources/statistics.txt");

// Outputter class
constexpr std::chrono::duration<long double> kCursorBlinkingDelay
  = std::chrono::milliseconds(400);

#endif // header guard