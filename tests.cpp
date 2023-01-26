#include <sstream>

#include "gtest/gtest.h"
#include "headers.h"

TEST(Range, Sorting) {
  std::vector<rec> list = {{46, 225, 43, 22}, {132, 144, 55, 46},
                           {14, 43, 221, 51}, {1, 12, 33, 76},
                           {4, 23, 46, 118},  {1, 22, 3, 44},
                           {46, 70, 55, 123}, {55, 34, 46, 111}};

  auto res = Sorting(list);
  std::vector<std::string> sort;
  std::stringstream ss;

  for (auto ip = 0; ip != res.size(); ++ip) {
    ss << std::get<0>(res[ip]) << "." << std::get<1>(res[ip]) << "."
       << std::get<2>(res[ip]) << "." << std::get<3>(res[ip]);
    sort.push_back(ss.str());
    ss.str("");
  }

  ASSERT_EQ(sort[0], "1.12.33.76");
  ASSERT_EQ(sort[sort.size() - 1], "132.144.55.46");
}

// TEST(Range, Sort1) {
//   Sort1();

//   ASSERT_EQ(res[0], "1.12.33.76");
//   ASSERT_EQ(res[1], "1.22.3.44");
// }

// TEST(Range, Sort4670) {
//   std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
//                            {14, 43, 221, 51}, {46, 225, 43, 22},
//                            {4, 23, 46, 118},  {1, 22, 3, 44},
//                            {46, 70, 55, 123}, {55, 34, 46, 111}};

//   auto res = Sort4670(Sorting(list));

//   ASSERT_EQ(res[0], "46.70.55.123");
// }

// TEST(Range, Any46sort) {
//   std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
//                            {14, 43, 221, 51}, {46, 225, 43, 22},
//                            {4, 23, 46, 118},  {1, 22, 3, 44},
//                            {46, 70, 55, 123}, {55, 34, 46, 111}};

//   auto res = Any46sort(Sorting(list));

//   ASSERT_EQ(res[0], "4.23.46.118");
//   ASSERT_EQ(res[1], "46.70.55.123");
//   ASSERT_EQ(res[2], "46.225.43.22");
//   ASSERT_EQ(res[3], "55.34.46.111");
// }

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}