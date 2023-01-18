#include <fstream>
#include <iostream>

#include "headers.h"

int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    std::cerr << "Error: program requres a parametr" << std::endl;
    return EXIT_FAILURE;
  }
  if (argc > 2) {
    std::cerr << "Error: programm accept only one parametr" << std::endl;
    return EXIT_FAILURE;
  }
  if (argc > 1) {
    std::ifstream input{argv[1]};
    if (!input.is_open()) {
      std::cerr << "Error: faild to open file" << argv[1] << std::endl;
      return EXIT_FAILURE;
    }

    run(input);
  }

  return 0;
}