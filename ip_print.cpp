#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace print {

template <typename N>
struct is_list : std::false_type {};

template <typename N>
struct is_list<typename std::list<N>> : std::true_type {};

template <typename N>
struct is_vector : std::false_type {};

template <typename N>
struct is_vector<typename std::vector<N>> : std::true_type {};

template <typename... Types>
struct is_tuple : std::false_type {};

template <typename... Types>
struct is_tuple<typename std::tuple<Types...>> : std::true_type {};

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, int8_t>::value>::type* = {}) {
  auto dex = std::bitset<8>(data).to_ulong();
  std::cout << std::dec << dex << std::endl;
}

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, int16_t>::value>::type* = {}) {
  std::string first_8, second_8;
  auto to_str = std::bitset<16>(data).to_string();
  for (size_t i = 0; i != to_str.size(); ++i) {
    if (i < 8) {
      first_8 += to_str[i];
    }
    if (i > 7) {
      second_8 += to_str[i];
    }
  }
  auto res1 = std::bitset<8>(first_8).to_ulong();
  auto res2 = std::bitset<8>(second_8).to_ulong();

  std::cout << std::dec << res1 << "." << res2 << std::endl;
}

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, int32_t>::value>::type* = {}) {
  std::string first_8, second_8, third_8, thouth_8;

  auto to_str = std::bitset<32>(data).to_string();
  for (size_t i = 0; i != to_str.size(); ++i) {
    if (i < 8) {
      first_8 += to_str[i];
    }
    if (i > 7 && i < 16) {
      second_8 += to_str[i];
    }
    if (i > 16 && i < 24) {
      third_8 += to_str[i];
    }
    if (i > 23 && i < 32) {
      thouth_8 += to_str[i];
    }
  }
  auto res1 = std::bitset<8>(first_8).to_ulong();
  auto res2 = std::bitset<8>(second_8).to_ullong();
  auto res3 = std::bitset<8>(third_8).to_ulong();
  auto res4 = std::bitset<8>(thouth_8).to_ulong();

  std::cout << std::dec << res1 << "." << res2 << "." << res3 << "." << res4
            << std::endl;
}

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, int64_t>::value>::type* = {}) {
  std::string first_8, second_8, third_8, thouth_8, thith_8, six_8, seven_8,
      eight_8;

  auto to_str = std::bitset<64>(data).to_string();
  for (size_t i = 0; i != to_str.size(); ++i) {
    if (i < 8) {
      first_8 += to_str[i];
    }
    if (i > 7 && i < 16) {
      second_8 += to_str[i];
    }
    if (i > 16 && i < 24) {
      third_8 += to_str[i];
    }
    if (i > 23 && i < 32) {
      thouth_8 += to_str[i];
    }
    if (i > 31 && i < 40) {
      thith_8 += to_str[i];
    }
    if (i > 39 && i < 48) {
      six_8 += to_str[i];
    }
    if (i > 47 && i < 56) {
      seven_8 += to_str[i];
    }
    if (i > 55 && i < 64) {
      eight_8 += to_str[i];
    }
  }
  auto res1 = std::bitset<8>(first_8).to_ulong();
  auto res2 = std::bitset<8>(second_8).to_ullong();
  auto res3 = std::bitset<8>(third_8).to_ulong();
  auto res4 = std::bitset<8>(thouth_8).to_ulong();
  auto res5 = std::bitset<8>(thith_8).to_ulong();
  auto res6 = std::bitset<8>(six_8).to_ulong();
  auto res7 = std::bitset<8>(seven_8).to_ulong();
  auto res8 = std::bitset<8>(eight_8).to_ulong();

  std::cout << std::dec << res1 << "." << res2 << "." << res3 << "." << res4
            << "." << res5 << "." << res6 << "." << res7 << "." << res8
            << std::endl;
}

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, std::string>::value>::type* = {}) {
  std::cout << data << std::endl;
}

template <typename T>
void print_ip(T& container,
              typename std::enable_if<is_vector<T>::value>::type* = {}) {
  n = 0;
  for
    size_t(const auto& i : container) {
      std::cout << i;
      ++n;
      if (n != container.size()) {
        std::cout << ".";
      }
    }
  std::cout << std::endl;
}

template <typename T>
void print_ip(T& container,
              typename std::enable_if<is_list<T>::value>::type* = {}) {
  size_t n = 0;
  for (const auto& i : container) {
    std::cout << i;
    ++n;
    if (n != container.size()) {
      std::cout << ".";
    }
  }
  std::cout << std::endl;
}

template <typename T>
void print_ip(T& container,
              typename std::enable_if<is_tuple<T>::value>::type* = {}) {
  std::cout << std::get<0>(container) << "." << std::get<1>(container) << "."
            << std::get<2>(container) << "." << std::get<3>(container)
            << std::endl;
}

}  // namespace print

void example() {
  int8_t data1{-1};
  int16_t data2{0};
  int32_t data3{2130706433};
  int64_t data4{8875824491850138409};
  std::string data5{"Hello, World!"};
  std::vector<int> data6{100, 200, 300, 400};
  std::list<short> data7{400, 300, 200, 100};
  auto data8 = std::make_tuple(123, 456, 789, 0);

  print::print_ip(data1);
  print::print_ip(data2);
  print::print_ip(data3);
  print::print_ip(data4);
  print::print_ip(data5);
  print::print_ip(data6);
  print::print_ip(data7);
  print::print_ip(data8);
}

int main() {
  example();
  return 0;
}