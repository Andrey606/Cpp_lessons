#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <my_class.h>

using namespace testing;

TEST(Calculator, TestDivisionByZero)
{
    my_class temp;
    ASSERT_EQ(2, temp.sum(1, 1));
    ASSERT_EQ(3, temp.sum(1, 2)) << "TEST NOT PASSED!1";

    EXPECT_EQ(1, 1);
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Calculator, TestDivisionByZero_2)
{
    my_class temp;
    ASSERT_EQ(2, temp.sum(1, 1));
    ASSERT_EQ(5, temp.sum(1, 4)) << "TEST NOT PASSED!2";

    EXPECT_EQ(1, 1);
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_TESTDIVISIONBYZERO_H
