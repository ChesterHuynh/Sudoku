#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include "helpers.h"
//#include "board.h"

using std::cout;    using std::endl;
using std::cin;     using std::string;

int main(int argc, char* argv[]) {
  srand(time(0)); // random seed
  char board[9][9];
  if (argc == 1) {
    /*Board newBoard;
    newBoard.allRowsValid();
    newBoard.allColsValid();
    newBoard.display();*/
    cout << "Generating New Board TODO" << endl;
  }
  else if (argc == 2) {
    std::ifstream is(argv[1]);
    if (is.fail()) {
      return 1; // failed to open file
    }
    char entry;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (is.eof()) {
          throw std::underflow_error("Not enough entries");
        }
        is >> entry;
        board[i][j] = entry;
      }
    }
  }
  cout << "Sudoku board was successfully loaded!" << endl;
  display(board);
  char move;
  cout << "What would you like to do:\n"
       << "(1) Add entry (indexing starts at 0 -- type a row #, col #, and entry to input)\n"
       << "(2) Remove entry (indexing starts at 0 -- type the row and col # of entry to delete)\n"
       << "(3) Save progress\n"
       << "(4) Solve\n"
       << "(5) Quit\n";
  cout << endl;

  while (cin >> move) {
    switch (move) {
      case '1': {
        int r, c;
        char entry;
        cin >> r >> c >> entry;
        add(board, r, c, entry);
        break;
      }
      case '2': {
        int r, c;
        cin >> r >> c;
        remove(board, r, c);
        break;
      }
      case '3': {
        save(board);
        break;
      }
      case '4': {
        solve(board);
        break;
      }
      case '5': {
        std::cout << "Thanks for playing!" << std::endl;
        return 0;
      }
      default: cout << "Invalid option." << endl;
    }
    display(board);
    cout << "What would you like to do:\n"
         << "(1) Add entry (indexing starts at 0 -- type a row #, col #, and entry to input)\n"
         << "(2) Remove entry (indexing starts at 0 -- type the row and col # of entry to delete)\n"
         << "(3) Save progress\n"
         << "(4) Solve\n"
         << "(5) Quit\n";
    cout << endl;
  }

  return 0;
}
