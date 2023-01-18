#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d) {
  std::vector<std::string> r;

  std::string::size_type start = 0;
  auto stop = str.find_first_of(d);
  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

std::vector<std::string> ReversSort(std::vector<std::string> rev) {
  std::vector<std::string> result;
  for (auto w = rev.size() - 1; w != -1; --w) {
    std::cout << rev[w] << std::endl;
    result.push_back(rev[w]);
  }
  return result;
}

std::vector<std::string> Sort1(std::vector<std::string> rev) {
  std::vector<std::string> result;
  for (const auto &w : rev) {
    if (!w.find("1.")) {
      std::cout << w << std::endl;
      result.push_back(w);
    }
  }
  return result;
}

std::vector<std::string> Sort4670(std::vector<std::string> rev) {
  std::vector<std::string> result;
  for (const auto &w : rev) {
    if (!w.find("46.70.")) {
      std::cout << w << std::endl;
      result.push_back(w);
    }
  }
  return result;
}

std::vector<std::string> Any46sort(std::vector<std::string> rev) {
  std::vector<std::string> result;
  for (const auto &w : rev) {
    if (w.find(".46") != w.npos || w.find(".46.") != w.npos || !w.find("46.")) {
      std::cout << w << std::endl;
      result.push_back(w);
    }
  }
  return result;
}

using rec = std::tuple<int, int, int, int>;

std::vector<std::string> Sorting(std::vector<rec> ip_list) {
  std::stable_sort(ip_list.begin(), ip_list.end(),
                   [](const rec &l, const rec &r) {
                     return std::get<3>(l) < std::get<3>(r);
                   });
  std::stable_sort(ip_list.begin(), ip_list.end(),
                   [](const rec &l, const rec &r) {
                     return std::get<2>(l) < std::get<2>(r);
                   });
  std::stable_sort(ip_list.begin(), ip_list.end(),
                   [](const rec &l, const rec &r) {
                     return std::get<1>(l) < std::get<1>(r);
                   });
  std::stable_sort(ip_list.begin(), ip_list.end(),
                   [](const rec &l, const rec &r) {
                     return std::get<0>(l) < std::get<0>(r);
                   });
  std::stringstream ss;
  std::vector<std::string> rev;
  for (const auto &t : ip_list) {
    ss << std::to_string(std::get<0>(t));
    ss << ".";
    ss << std::to_string(std::get<1>(t));
    ss << ".";
    ss << std::to_string(std::get<2>(t));
    ss << ".";
    ss << std::to_string(std::get<3>(t));
    rev.push_back(ss.str());
    ss.str("");
  }
  return rev;
}

void run(std::ifstream &input) {
  try {
    std::vector<rec> ip_list;
    for (std::string line; std::getline(input, line);) {
      auto v = split(line, '\t');
      auto vt = (split(v.at(0), '.'));
      for (auto z = 0; z != vt.size(); z += 4) {
        ip_list.push_back(std::make_tuple(stoi(vt[z]), stoi(vt[z + 1]),
                                          stoi(vt[z + 2]), stoi(vt[z + 3])));
      }
    }

    ReversSort(Sorting(ip_list));
    Sort1(Sorting(ip_list));
    Sort4670(Sorting(ip_list));
    Any46sort(Sorting(ip_list));

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

// TODO reverse lexicographically sort
//   std::vector<std::string> ip_list;

//   for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
//     for (auto ip_part = ip->cbegin(); ip_part != ip->cend();
//     ++ip_part)
//     {
//       if (ip_part != ip->cbegin()) {
//         ss << ".";
//       }
//       //   ss << *ip_part;
//     }
//     ss << std::endl;
//   }
//   //   ip_list.push_back(ss.str());
//   for (auto q : ip_list) {
//     std::cout << q << std::endl;
//   }

// 222.173.235.246
// 222.130.177.64
// 222.82.198.61
// ...
// 1.70.44.170
// 1.29.168.152
// 1.1.234.8

// TODO filter by first byte and output
// ip = filter(1)

// 1.231.69.33
// 1.87.203.225
// 1.70.44.170
// 1.29.168.152
// 1.1.234.8

// TODO filter by first and second bytes and output
// ip = filter(46, 70)

// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76

// TODO filter by any byte and output
// ip = filter_any(46)

// 186.204.34.46
// 186.46.222.194
// 185.46.87.231
// 185.46.86.132
// 185.46.86.131
// 185.46.86.131
// 185.46.86.22
// 185.46.85.204
// 185.46.85.78
// 68.46.218.208
// 46.251.197.23
// 46.223.254.56
// 46.223.254.56
// 46.182.19.219
// 46.161.63.66
// 46.161.61.51
// 46.161.60.92
// 46.161.60.35
// 46.161.58.202
// 46.161.56.241
// 46.161.56.203
// 46.161.56.174
// 46.161.56.106
// 46.161.56.106
// 46.101.163.119
// 46.101.127.145
// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76
// 46.55.46.98
// 46.49.43.85
// 39.46.86.85