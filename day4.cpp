#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#define N 1024

int get_full_number(std::string curr_line, int &idx);

int main() {
  std::string curr_line;
  std::ifstream input_file("./input4.txt");

  int wins{0};

  int winners[N];
  int our_card[N];
  int nums{0};

  int i{0};
  if (input_file.is_open()) {
    while (std::getline(input_file, curr_line)) {

      // read winners
      i = 0;
      int idx = 8;
      for (idx; idx < curr_line.length(); i++) {
        int ret = get_full_number(curr_line, idx);
        if (ret == 0) break; // winners over
        winners[i] = ret;
      }
      idx++;
      nums = i;
      i = 0;

      // read our vals
      for (idx; idx < curr_line.length(); i++) {
        int ret = get_full_number(curr_line, idx);
        if (ret == 0) break; // vals over
        our_card[i] = ret;
      }
      i = 0;

      for (int j{0}; j < nums; j++) {
        std::cout << winners[j] << " ";
      }
      std::cout << std::endl;
      for (int j{0}; j < nums; j++) {
        std::cout << our_card[j] << " ";
      }
      std::cout << std::endl;

      wins = 0;
      for (int j{0}; j < nums; j++) {
        for (int k{0}; k < nums; k++) {
          if (winners[j] == our_card[k]) {
            wins = wins == 0 ? 1 : wins*2;
          }
        }
      }

      std::cout << "Wins: " << wins << std::endl;
    }
  }

}

int get_full_number(std::string curr_line, int &idx) {
  char str[N];

  // go to start of number
  // while the thing is still a number
  while (curr_line[idx] >= 48 && curr_line[idx] <= 57) {
    idx--;
  }
  idx++; // undo the last col-- that caused loop to break;

  // walk until number ends
  int i{0};
  while (curr_line[idx] >= 48 && curr_line[idx] <= 57) {
    str[i] = curr_line[idx];
    i++;
    idx++;
  }
  str[i] = '\0';

  try {
    return std::stoi(str);
  } catch (const std::exception&) {
    idx++;
    return 0;
  }
}
