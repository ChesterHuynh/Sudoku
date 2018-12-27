#include <iostream>
#include <random>
#include <vector>

class Subsection {
private:
  char** cells;
public:

  Subsection() {
    cells = new char*[3];
    for (int i = 0; i < 3; i++) {
      cells[i] = new char[3];
    }
  }

  ~Subsection() {
    for (int i = 0; i < 3; i++) {
      delete[] cells[i];
    }
    delete[] cells;
  }

  void setHiddens();

  void setCells();

  void setEntry(int r, int c, char entry);

  char getEntry(int i, int j);
};
