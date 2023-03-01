#include <iostream>
#include <map>
#include <vector>

template <typename T, size_t size>
struct my_allocator {
 public:
  using value_type = T;

  template <typename U>
  struct rebind {
    using other = my_allocator<U, size>;
  };

  my_allocator() = default;
  ~my_allocator() { std::free(m_memory); }

  template <typename U>
  my_allocator(const my_allocator<U, size> &) {}

  T *allocate(std::size_t n) {
    if (m_memory == nullptr) {
      m_memory = reinterpret_cast<T *>(std::malloc((size + 1) * sizeof(T)));
      if (!m_memory) {
        throw std::bad_alloc();
      }
    }
    if (size - m_count < n) {
      throw std::bad_alloc();
    }
    T *result = m_memory + m_count;
    m_count += n;
    return result;
  }

  void deallocate(T *, std::size_t) noexcept {}

  template <typename U, typename... Args>
  void construct(U *p, Args &&...args) {
    new (p) U(std::forward<Args>(args)...);
  }

  template <typename U>
  void destroy(U *p) {
    p->~U();
  }

 private:
  T *m_memory = nullptr;
  size_t m_count = 0;
};

int factorial(int n) {
  int res = 1;
  for (int i = 1; i < n + 1; ++i) {
    res *= i;
  }
  return res;
}

int main(int, char *[]) {
  auto m = std::map<int, int, std::less<int>,
                    my_allocator<std::pair<const int, int>, 10>>{};

  for (int i = 0; i < 10; ++i) {
    m.emplace(i, factorial(i));
  }

  for (const auto &data : m) {
    std::cout << data.first << "--->" << data.second << std::endl;
  }
  return 0;
}
