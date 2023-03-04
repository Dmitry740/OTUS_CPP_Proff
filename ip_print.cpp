#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
void print_ip(T& data,
              typename std::enable_if<
                  std::is_integral<T>::value && !std::is_same<T, bool>::value &&
                  !std::is_same<T, char>::value>::type* = {}) {
  auto to_unchar = reinterpret_cast<unsigned char*>(&data);
  auto n = 0;
  for (auto i = sizeof(to_unchar) - 1; i != -1; --i) {
    ++n;
    if (std::bitset<8>(to_unchar[i]).to_ullong() != 204) {
      std::cout << std::dec << std::bitset<8>(to_unchar[i]).to_ullong();
      if (n != sizeof(to_unchar)) {
        std::cout << ".";
      }
    }
  }
  std::cout << std::endl;
}

template <typename T>
void print_ip(
    T& data,
    typename std::enable_if<std::is_same<T, std::string>::value>::type* = {}) {
  std::cout << data << std::endl;
}

template <typename T>
void print_ip(const T& container,
              typename std::enable_if<is_vector<T>::value ||
                                      is_list<T>::value>::type* = {}) {
  auto n = 0;
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
void print_ip(const T& container,
              typename std::enable_if<is_tuple<T>::value>::type* = {}) {
  std::apply(
      [](auto&&... args) {
        size_t n{0};
        ((std::cout << args << (++n != std::tuple_size<T>{} ? "." : "")), ...);
      },
      container);
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