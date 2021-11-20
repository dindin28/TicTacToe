#ifndef TICTACTOE_SRC_STATISTICKS_H
#define TICTACTOE_SRC_STATISTICKS_H

class Statisticks
{
 public:
  Statisticks();
  bool ReadFile();   // return false on error
  bool UpdateFile(); // return false on error

  void IncrementNoughts();
  void IncrementCrosses();
  void IncrementDraws();

  const unsigned int GetNoughts() const;
  const unsigned int GetCrosses() const;
  const unsigned int GetDraws() const;

 private:
  unsigned int noughts_;
  unsigned int crosses_;
  unsigned int draws_;

  // false at creating, true - after ReadFile function
  bool file_readed_;
};

#endif // header guard