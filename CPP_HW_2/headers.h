#pragma once
#include <string>
#include <vector>

using rec = std::tuple<int, int, int, int>;

std::vector<std::string> split(const std::string &str, char d);

void run(std::ifstream &input);

std::vector<std::string> Sorting(std::vector<rec> ip_list);

std::vector<std::string> ReversSort(std::vector<std::string> rev);

std::vector<std::string> Sort1(std::vector<std::string> rev);

std::vector<std::string> Sort4670(std::vector<std::string> rev);

std::vector<std::string> Any46sort(std::vector<std::string> rev);