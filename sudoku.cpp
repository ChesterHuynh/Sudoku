#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "board.h"

using std::cout;  using std::endl;
using std::string;

int main() {

  srand(time(0)); // random seed

  // initializing a sudoku board array
  Board b;
  b.display();

  return 0;
}
