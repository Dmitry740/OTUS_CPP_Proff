#pragma once
#include <string>
#include <vector>

using rec = std::tuple<int, int, int, int>;

std::vector<std::string> split(const std::string &str, char d);

void run(std::ifstream &input);

std::vector<std::string> Sorting(std::vector<rec> ip_list);

std::vector<std::string> ReversSort(const std::vector<std::string> &rev);

std::vector<std::string> Sort1(const std::vector<std::string> &rev);

std::vector<std::string> Sort4670(const std::vector<std::string> &rev);

std::vector<std::string> Any46sort(const std::vector<std::string> &rev);