#pragma once
#include <string>
#include <vector>

using rec = std::tuple<int, int, int, int>;

std::vector<std::string> split(const std::string &str, char d);

void run(std::ifstream &input);

std::vector<rec> Sorting(std::vector<rec> ip_list);

void ReversSort(const std::vector<rec> &ip_list);

void Sort1(const std::vector<rec> &ip_list);

void Sort4670(const std::vector<rec> &ip_list);

void Any46sort(const std::vector<rec> &ip_list);