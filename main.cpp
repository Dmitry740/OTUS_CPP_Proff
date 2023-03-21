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

  controll.create_obj();
  controll.create_obj();
  controll.create_obj();

  std::cout << "object opertions #1" << std::endl;
  controll.view_obj_res();
  std::cout << std::endl;

  controll.delete_obj();

  std::cout << "object opertions #2" << std::endl;
  controll.view_obj_res();

  return 0;
}