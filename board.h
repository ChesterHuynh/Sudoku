#include "subsections.h"

class Board {
private:
  Subsection bd[3][3];
public:
  Board();

  ~Board() { ;}

  void display();

  void makeValidRow(int idx);

  void makeValidCol(int idx);

  void allRowsValid();

  void allColsValid();
};
