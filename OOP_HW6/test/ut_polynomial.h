#include <gtest/gtest.h>
#include "../src/polynomial.h"
#include "../src/term.h"
class PolynomialTest : public ::testing::Test {
protected:
    std::vector<Term> terms1,terms2;
    void SetUp() override {
        terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};   //6x3 + -3x2  0x1 3x0
        terms2 = {Term(-5 ,1), Term(7, 0), Term(1, 2)};   //0x3 +  1x2 -5x1 7x0
    }
};
TEST_F(PolynomialTest, termtest) {
    Polynomial p(terms1, 3);
    ASSERT_EQ(3,p.degree());
}
TEST_F(PolynomialTest, operator_plus) {
    Polynomial p1(terms1,3);
    Polynomial p2(terms2,2);
    //ASSERT_THROW (p1 + p2,std::string);
    ASSERT_NEAR(6.0,(p1 + p2).term(3).coefficient(),0.1);
}
TEST_F(PolynomialTest, operator_multiply_term) {
    Polynomial p1(terms1,3);
    Term tt(-5 ,2);
    ASSERT_EQ(5.0,(p1 * tt).degree());
}
TEST_F(PolynomialTest, operator_multiply_polynomial) {
    Polynomial p1(terms1,3);
    Polynomial p2(terms2,2);
    ASSERT_THROW (p1 + p2,std::string);
    // ASSERT_NEAR(6.0,(p1 + p2).term(3).coefficient(),0.1);
}
