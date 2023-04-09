#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <tuple>

template <typename T, int U = -1>
class Matrixx {
  using IterType = typename std::map<std::pair<int, int>, T>::iterator;

 public:
  Matrixx() : m_defaultelem{U} {};

  ~Matrixx() {}

  class Helper {
   public:
    Helper(Matrixx* matr, size_t x) : m_x{x}, m_matr{matr}, m_element{0} {}

    ~Helper() {}

    Helper& operator[](size_t y) {
      cord = std::make_pair(m_x, y);
      m_element = m_matr->find(cord);
      return *this;
    }

    void operator=(T val) {
      if (val != m_matr->getDefaultElement()) {
        if (m_element != m_matr->getDefaultElement()) {
          m_element = val;
        } else {
          m_matr->insert(cord, val);
        }
      } else {
        if (m_element != m_matr->getDefaultElement()) {
          m_matr->erase(cord);
          return;
        } else
          return;
      }
    }

    operator T() { return m_element; }

   private:
    size_t m_x{0};
    Matrixx* m_matr{nullptr};
    std::pair<int, int> cord;
    T m_element;
  };

  Helper operator[](size_t index) {
    Helper helper(this, index);
    return helper;
  }

  const T& find(std::pair<int, int> coordinates) const {
    auto it = m_matrix.find(coordinates);
    if (it == m_matrix.end()) {
      return m_defaultelem;
    } else {
      return it->second;
    }
  }

  size_t size() {
    auto size = m_matrix.size();
    return size;
  }

  void insert(std::pair<int, int> coordinates, T value) {
    m_matrix.emplace(coordinates, value);
  }

  void erase(std::pair<int, int> coordinates) {
    m_matrix.erase(m_matrix.find(coordinates));
  }

  T getDefaultElement() { return m_defaultelem; };

  class Iterator {
   public:
    Iterator(IterType it) : m_iterator{it} {}

    IterType getIter() { return this->m_iterator; }

    std::tuple<int, int, T> operator*() {
      return std::make_tuple(m_iterator->first.first, m_iterator->first.second,
                             m_iterator->second);
    }

    void operator++() { m_iterator++; }

    void operator--() { m_iterator--; }

    bool operator==(Iterator& it) { return m_iterator == it.getIter() }
    bool operator!=(Iterator& it) { return m_iterator != it.getIter(); }

   private:
    IterType m_iterator;
  };

  Iterator begin() { return Iterator{m_matrix.begin()}; }

  Iterator end() { return Iterator{m_matrix.end()}; }

 private:
  T m_defaultelem;
  std::map<std::pair<int, int>, T> m_matrix;
};

void example_1() {
  Matrixx<int, -1> matrix;

  assert(matrix.size() == 0);
  auto a = matrix[0][0];
  assert(a == -1);
  assert(matrix.size() == 0);
  matrix[100][100] = 314;
  assert(matrix[100][100] == 314);
  assert(matrix.size() == 1);
  matrix[100][100] = -1;
  assert(matrix[100][100] == -1);
  assert(matrix.size() == 0);

  for (auto i = 0; i < 10; i++) matrix[i][i] = i;
  for (auto i = 0, j = 9; i < 10; i++, j--) matrix[i][j] = j;

  std::cout << "size: " << matrix.size() << std::endl;

  for (auto c : matrix) {
    int x, y, v;
    std::tie(x, y, v) = c;
    std::cout << "[" << x << "]"
              << "[" << y << "]"
              << " value: " << v << std::endl;
  }

  for (auto i = 1; i < 9; i++) {
    for (auto j = 1; j < 9; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  example_1();
  return 0;
}
