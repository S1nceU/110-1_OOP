#include <gtest/gtest.h>
#include "../src/fraction.h"
#include "../src/gcd.h"
class FractionTest : public ::testing::Test {
protected:
    int a1,b1;
    int a2,b2;
    int a3,b3;
    int a4,b4;
    void SetUp() override {
        a1 = 2;
        b1 = -3;
        a2 = 7;
        b2 = 3;
        a3 = 15;
        b3 = 1234567;
        a4 = -16;


    }
};
TEST_F(FractionTest, numeratorTest) {
    Fraction op(a1,b1);
    ASSERT_EQ(2,op.numerator());
}
TEST_F(FractionTest, denominatorTest) {
    Fraction op(a2,b2);
    ASSERT_EQ(3,op.denominator());
}
TEST_F(FractionTest, signTest) {
    Fraction op(a1,b1);
    ASSERT_EQ('-',op.sign());
}
TEST_F(FractionTest, selow) {
    Fraction op(a4);
    ASSERT_EQ("-16",op.toString());
}
