#include <iostream>

void display(char arr[][9]);

void add(char board[][9], int r, int c, char entry);

void remove(char board[][9], int r, int c);

void save(char board[][9]);

bool checkRowValidity(char board[][9], int row);

bool checkColValidity(char board[][9], int col);

bool checkBoxValidity(char board[][9], int startRow, int startCol);

bool isValidBoard(char board[][9]);

bool usedInRow(char board[][9], int row, int num);

bool usedInCol(char board[][9], int col, int num);

bool usedInBox(char board[][9], int startRow, int startCol, int num);

bool isSafe(char board[][9], int row, int col, int num);

bool findUnassignedLocation(char board[][9], int &row, int &col);

bool solve(char board[][9]);
