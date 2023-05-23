#include "headers.h"

int main() {
  Controller controll;

  controll.create_file();
  controll.import_file();
  controll.export_file();

  std::cout << "file opertions #1" << std::endl;
  controll.view_file_res();
  std::cout << std::endl;

  controll.create_file();
  controll.import_file();
  controll.import_file();
  controll.export_file();
  controll.export_file();
  controll.export_file();

  std::cout << "file opertions #2" << std::endl;
  controll.view_file_res();
  std::cout << std::endl;

  controll.delete_file();

  std::cout << "file opertions #3" << std::endl;
  controll.view_file_res();
  std::cout << std::endl;

  std::cout << "primitive opertions #1" << std::endl;
  controll.create_dot();
  controll.create_dot();
  controll.create_dot();
  controll.create_dot();
  controll.get_dots_coord();
  std::cout << std::endl;
  controll.erase_dot(3);
  controll.get_dots_coord();

  std::cout << "primitive opertions #2" << std::endl;
  controll.create_line();
  controll.create_line();
  controll.create_line();
  controll.create_line();
  controll.get_lines_coord();
  std::cout << std::endl;

  controll.erase_line(2);
  controll.get_lines_coord();

  return 0;
}