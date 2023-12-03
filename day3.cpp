#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

#define N 2048

bool is_symbol(char schematic[N][N], int row, int col);
int get_full_number(char schematic[N][N], int row, int &col);
int sum_neighbors(char schematic[N][N], int symbol_row, int symbol_col);
int prod_ratio(char schematic[N][N], int symbol_row, int symbol_col);

int main() {
  std::string curr_line;
  std::ifstream input_file("./input3.txt");

  char schematic[N][N];

  int lines{0};
  int cols{0};

  if (input_file.is_open()) {
    while (std::getline(input_file, curr_line)) {
      cols = curr_line.length();

      for (int i{0}; i < cols; i++) {
        schematic[lines][i] = curr_line[i];
      }

      lines++;
    }
  }

  // part 1
  int sum{0};
  for (int row{0}; row < lines; row++) {
    for (int col{0}; col < cols; col++) {
      // if not symbol, dip
      if (!is_symbol(schematic, row, col)) continue;

      sum += sum_neighbors(schematic, row, col);
    }
  }

  std::cout << "Part 1: " << sum << std::endl;

  int gear_ratio{0};
  for (int row{0}; row < lines; row++) {
    for (int col{0}; col < cols; col++) {
      // if not gear, dip
      if (schematic[row][col] != '*') continue;

      gear_ratio += prod_ratio(schematic, row, col);
    }
  }
  std::cout << "Part 2: " << gear_ratio << std::endl;
}

bool is_symbol(char schematic[N][N], int row, int col) {
  if (schematic[row][col] == 46) return false; // if full stop
  if (schematic[row][col] >= 48 && schematic[row][col] <= 57) return false; // if number

  return true; // potential issue if control sequences are symbols lol
}

// consumes ref to `x` so that the digits of the same number do not trigger repeats
int get_full_number(char schematic[N][N], int row, int &col) {
  char str[N];

  // go to start of number
  // while the thing is still a number
  while (schematic[row][col] >= 48 && schematic[row][col] <= 57) {
    col--;
  }
  col++; // undo the last col-- that caused loop to break;

  // walk until number ends
  int i{0};
  while (schematic[row][col] >= 48 && schematic[row][col] <= 57) {
    str[i] = schematic[row][col];
    i++;
    col++;
  }
  str[i] = '\0';

  return std::stoi(str);
}

int sum_neighbors(char schematic[N][N], int symbol_row, int symbol_col) {
  int sum{0};

  // walk on neighbours
  for (int row{ symbol_row - 1}; row <= symbol_row + 1; row++) {
    for (int col{ symbol_col - 1}; col <= symbol_col + 1; col++) {
      // if said neighbour is not number, dip
      if (!(schematic[row][col] >= 48 && schematic[row][col] <= 57)) continue;

      int curr_num = get_full_number(schematic, row, col);
      sum += curr_num;
    }
  }

  return sum;
}

int prod_ratio(char schematic[N][N], int symbol_row, int symbol_col) {
  int adj{0};
  int nums[2];

  int i{0};
  for (int row{ symbol_row - 1}; row <= symbol_row + 1; row++) {
    for (int col{ symbol_col - 1}; col <= symbol_col + 1; col++) {
      // if said neighbour is not number, dip
      if (!(schematic[row][col] >= 48 && schematic[row][col] <= 57)) continue;
      nums[i] = get_full_number(schematic, row, col);
      adj++;
      i++;
    }
  }

  if (adj != 2) return 0;
  return nums[0] * nums[1];
}
