#include "gtest/gtest.h"
#include "headers.h"

TEST(Range, ReverseSort) {
  std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
                           {14, 43, 221, 51}, {46, 225, 43, 22},
                           {4, 23, 46, 118},  {1, 22, 3, 44},
                           {46, 70, 55, 123}, {55, 34, 46, 111}};

  auto res = ReversSort(Sorting(list));

  ASSERT_EQ(res[0], "132.144.55.46");
  ASSERT_EQ(res[res.size() - 1], "1.12.33.76");
}

TEST(Range, Sort1) {
  std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
                           {14, 43, 221, 51}, {46, 225, 43, 22},
                           {4, 23, 46, 118},  {1, 22, 3, 44},
                           {46, 70, 55, 123}, {55, 34, 46, 111}};

  auto res = Sort1(Sorting(list));

  ASSERT_EQ(res[0], "1.12.33.76");
  ASSERT_EQ(res[1], "1.22.3.44");
}

TEST(Range, Sort4670) {
  std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
                           {14, 43, 221, 51}, {46, 225, 43, 22},
                           {4, 23, 46, 118},  {1, 22, 3, 44},
                           {46, 70, 55, 123}, {55, 34, 46, 111}};

  auto res = Sort4670(Sorting(list));

  ASSERT_EQ(res[0], "46.70.55.123");
}

TEST(Range, Any46sort) {
  std::vector<rec> list = {{1, 12, 33, 76},   {132, 144, 55, 46},
                           {14, 43, 221, 51}, {46, 225, 43, 22},
                           {4, 23, 46, 118},  {1, 22, 3, 44},
                           {46, 70, 55, 123}, {55, 34, 46, 111}};

  auto res = Any46sort(Sorting(list));

  ASSERT_EQ(res[0], "4.23.46.118");
  ASSERT_EQ(res[1], "46.70.55.123");
  ASSERT_EQ(res[2], "46.225.43.22");
  ASSERT_EQ(res[3], "55.34.46.111");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}