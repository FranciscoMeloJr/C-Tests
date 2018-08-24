//POD example:
//https://stackoverflow.com/questions/2218254/variable-initialization-in-c
#include <iostream>

int main() {
  int i = int();
  int j;

  std::cout << "i: " << i << std::endl;
  // warning: undefined behavior
  std::cout << "j: " << j << std::endl;
}
