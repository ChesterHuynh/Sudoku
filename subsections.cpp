#include <iostream>
#include <random>
#include <vector>
#include "subsections.h"

using std::vector;

void Subsection::setHiddens() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cells[i][j] = rand() % 2;
    }
  }
}

void Subsection::setCells() {
  vector<char> vec;
  for (int i = 1; i <= 9; i++) {
    vec.push_back('0' + i);
  }
  int random = rand() % vec.size();
  std::shuffle(vec.begin(), vec.end(), std::default_random_engine(random));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (cells[i][j]) {
        cells[i][j] = vec.back();
        vec.pop_back();
      }
      else {
        cells[i][j] = ' ';
      }
    }
  }
}

char Subsection::getEntry(int i, int j) {
  return cells[i][j];
}

void Subsection::setEntry(int r, int c, char entry) {
  cells[r][c] = entry;
}
