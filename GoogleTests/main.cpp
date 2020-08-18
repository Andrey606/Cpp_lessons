#include "gtest/gtest.h"
 
double square_root (double num) 
{ 
    if (num < 0.0) { 
        std::cerr << "Error: Negative Input\n";
        exit(-1);
    }
    // Код для 0 и положительных чисел…
}
 
TEST (SquareRootTest, ZeroAndNegativeNos) 
{ 
    ASSERT_EQ(0.0, square_root(0.0));
    ASSERT_EXIT(square_root(-22.0), ::testing::ExitedWithCode(-1), "Error: Negative Input");
}
 
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}