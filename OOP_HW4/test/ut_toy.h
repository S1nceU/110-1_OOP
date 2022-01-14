#include <gtest/gtest.h>
#include "../src/toy.h"

TEST(VectorTest, ToygetName) {
    Toy cat1("Sophia");
    EXPECT_EQ(cat1.getName(),"Sophia");
}