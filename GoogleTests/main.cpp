#include "gtest/gtest.h"

 
double square_root (double num) 
{ 
    if (num < 0.0) { 
        std::cerr << "Error: Negative Input\n";
        exit(255);
    }
    // Код для 0 и положительных чисел…
    return num;
}
 
TEST (SquareRootTest, ZeroAndNegativeNos) 
{ 
    ASSERT_EQ(0.0, square_root(0.0));
    ASSERT_EQ(0.1, square_root(0.1));
    ASSERT_EQ(0.2, square_root(0.2));
    ASSERT_EQ(0.2, square_root(0.2));
    ASSERT_EQ(0.2, square_root(0.2));
    ASSERT_EXIT(square_root(-22.0), ::testing::ExitedWithCode(255), "Error: Negative Input\n");
}

TEST (SquareRootTest, ZeroAndNegativeNosDva) 
{ 
    ASSERT_EQ(0.0, square_root(0.0));
    ASSERT_EQ(0.1, square_root(0.1));
    ASSERT_EQ(0.2, square_root(0.2));
    ASSERT_EQ(0.2, square_root(0.2));
    ASSERT_EQ(0.2, square_root(0.3));
    ASSERT_EXIT(square_root(-22.0), ::testing::ExitedWithCode(255), "Error: Negative Input\n");
}
 
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}