#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "helpers.h"


using std::cout;    using std::endl;
using std::string;  using std::cin;
using std::vector;

void display(char board[][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++){
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
}

void add(char board[][9], int r, int c, char entry) {
  board[r][c] = entry;
}

void remove(char board[][9], int r, int c) {
  board[r][c] = '.';
}

void save(char board[][9]) {
  cout << "save filename: ";
  string filename;
  cin >> filename;
  std::ofstream savefile(filename);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      savefile << board[i][j];
    }
  }
  savefile.close();
}

bool checkRowValidity(char board[][9], int row) {
  vector<char> numsInRow;
  for (int col = 0; col < 9; col++) {
    if (std::find(numsInRow.begin(), numsInRow.end(), board[row][col]) != numsInRow.end()) {
      return false;
    }
    if (board[row][col] != '.') {
      numsInRow.push_back(board[row][col]);
    }
  }
  return true;
}

bool checkColValidity(char board[][9], int col) {
  vector<char> numsInCol;
  for (int row = 0; row < 9; row++) {
    if (std::find(numsInCol.begin(), numsInCol.end(), board[row][col]) != numsInCol.end()) {
      return false;
    }
    if (board[row][col] != '.') {
      numsInCol.push_back(board[row][col]);
    }
  }
  return true;
}

bool checkBoxValidity(char board[][9], int startRow, int startCol) {
  vector<char> numsInBox;
  for (int row = startRow; row < startRow + 3; row++) {
    for (int col = startCol; col < startCol + 3; col++) {
      if (std::find(numsInBox.begin(), numsInBox.end(), board[row][col]) != numsInBox.end()) {
        return false;
      }
      if (board[row][col] != '.') {
        numsInBox.push_back(board[row][col]);
      }
    }
  }
  return true;
}

bool isValidBoard(char board[][9]) {
  for (int i = 0; i < 9; i++) {
    bool row = checkRowValidity(board, i);
    bool col = checkColValidity(board, i);
    if (!row || !col) {
      return false;
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      bool box = checkBoxValidity(board, i - i%3, j - j%3);
      if (!box) {
        return false;
      }
    }
  }
  return true;
}

bool findUnassignedLocation(char board[][9], int& row, int& col) {
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (board[row][col] == '.') {
        return true;
      }
    }
  }
  return false;
}

bool usedInRow(char board[][9], int row, int num) {
  for (int col = 0; col < 9; col++) {
    if (board[row][col] == '0' + num) {
      return true;
    }
  }
  return false;
}

bool usedInCol(char board[][9], int col, int num) {
  for (int row = 0; row < 9; row++) {
    if (board[row][col] == '0' + num) {
      return true;
    }
  }
  return false;
}

bool usedInBox(char board[][9], int startRow, int startCol, int num) {
  for (int row = startRow; row < startRow + 3; row++) {
    for (int col = startCol; col < startCol + 3; col++) {
      if (board[row][col] == '0' + num) {
        return true;
      }
    }
  }
  return false;
}

bool isSafe(char board[][9], int row, int col, int num) {
  return (!usedInRow(board, row, num) && !usedInCol(board, col, num) && !usedInBox(board, row - row % 3, col - col % 3, num));
}

bool solve(char board[][9]) {
  int row = 0, col = 0;
  if (!findUnassignedLocation(board, row, col)) {
    return true; // no empty spaces
  }
  for (int num = 1; num <= 9; num++) {
    if (isSafe(board, row, col, num)) {
      board[row][col] = '0' + num;
      if (solve(board)) {
        return true;
      }
      board[row][col] = '.';
    }
  }

  return false;
}
