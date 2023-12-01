#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main() {
  int sum{0};
  std::string str_line;
  std::ifstream input_file("./input1.txt");

  if (input_file.is_open()) {
    while (std::getline(input_file, str_line)) {

      //std::stringstream int_str;
      for (int i{0}; i < str_line.length(); i++) {
        if (str_line[i] >= 48 && str_line[i] <= 57) {
          sum += 10*(str_line[i] - 48);
          break;
        }
      }

      for (int i = str_line.length() - 1; i >= 0; i--) {
        if (str_line[i] >= 48 && str_line[i] <= 57) {
          sum += (str_line[i] - 48);
          break;
        }
      }
    }

    std::cout << "Sum: " << sum << std::endl;
  }
}
