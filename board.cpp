#include "board.h"
#include <iostream>
#include <vector>

using std::cout;    using std::endl;
using std::vector;  using std::find;

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

void Board::makeValidRow(int idx) {
  vector<char> numsInRow;
  int boardIdx = idx / 3;
  int subsectionIdx = idx % 3;
  for (int scol = 0; scol < 3; scol++) {
    for (int col = 0; col < 3; col++) {
        char entry = bd[boardIdx][scol].getEntry(subsectionIdx, col);
      if (find(numsInRow.begin(), numsInRow.end(), entry) != numsInRow.end()) {
        bd[boardIdx][scol].setEntry(subsectionIdx, col, ' ');
      }
      else {
        numsInRow.push_back(bd[boardIdx][scol].getEntry(subsectionIdx, col));
      }
    }
  }
}

void Board::makeValidCol(int idx) {
  vector<char> numsInCol;
  int boardIdx = idx / 3;
  int subsectionIdx = idx % 3;
  for (int srow = 0; srow < 3; srow++) {
    for (int row = 0; row < 3; row++) {
        char entry = bd[srow][boardIdx].getEntry(row, subsectionIdx);
      if (find(numsInCol.begin(), numsInCol.end(), entry) != numsInCol.end()) {
        bd[srow][boardIdx].setEntry(row, subsectionIdx, ' ');
      }
      else {
        numsInCol.push_back(bd[srow][boardIdx].getEntry(row, subsectionIdx));
      }
    }
  }
}

void Board::allRowsValid() {
  for (int r = 0; r < 9; r++) {
    makeValidRow(r);
  }
}

void Board::allColsValid() {
  for (int c = 0; c < 9; c++) {
    makeValidCol(c);
  }
}
