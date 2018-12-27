#include <iostream>
#include <fstream>
#include <string>
#include "helpers.h"


using std::cout;    using std::endl;
using std::string;  using std::cin;


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

void solve(char board[][9]) {
  return;
}
