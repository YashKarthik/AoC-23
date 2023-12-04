#include <iostream>

#define N 10

void t(char s[N][N]) {
  std::cout << s[0][1] << std::endl;
  std::cout << s[0][2] << std::endl;
}

int main() {
  char s[N][N];
  s[0][1] = '0';
  s[0][2] = '0';

  std::cout << s[0][1] << std::endl;
  std::cout << s[0][2] << std::endl;

  t(s);
}
