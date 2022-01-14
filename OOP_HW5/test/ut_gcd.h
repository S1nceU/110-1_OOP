#include <gtest/gtest.h>
#include "../src/gcd.h"
TEST(GCDTest, getGCD) {
    int a = 3;
    int b = 2;
    ASSERT_EQ(1,gcd(a,b));
}