#include "subsections.h"

class Board {
private:
  Subsection bd[3][3];
public:
  Board();

  ~Board() { ;}

  void display();
};
