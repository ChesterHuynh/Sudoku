#include "board.h"
#include <iostream>

using std::cout;  using std::endl;


Board::Board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      bd[i][j].setHiddens();
      bd[i][j].setCells();
    }
  }
}

void Board::display() {
  cout << "-----------------------" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          cout << bd[i][k].getEntry(j, l) << ' ';
        }
        cout << "| ";
      }
      cout << endl;
    }
    cout << "-----------------------" << endl;
  }
}
