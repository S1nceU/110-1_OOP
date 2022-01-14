#include "../src/cat.h"
#include <gtest/gtest.h>
#include "../src/toy.h"
TEST(VectorTest,constructor_throw) {
    
    ASSERT_THROW(Cat cat3("Baba",65.0),std::string);
}
TEST(VectorTest,constructor) {
    std::string name = "Yaga";
    double weight = 24.0;
    Cat cat4(name,weight);
    Toy t1("pussy");
    Toy t2("booble");
    Toy t3("nips");
    cat4.addNewToy(t1);
    cat4.addNewToy(t2);
    cat4.addNewToy(t3);
    Cat cat3 = Cat(cat4);
    EXPECT_EQ("Yaga",cat3.getName());
    EXPECT_NEAR(24.0,cat3.getWeight(),0.01);
}
TEST(VectorTest,operatorEQ) {
    Cat cat3("Baba",40.0);
    Cat cat4("Yaga",24.0);
    cat3 = cat4;
    EXPECT_EQ(cat3.getName(),"Yaga");
    EXPECT_NEAR(24.0,cat3.getWeight(),0.01);
}

TEST(VectorTest, addnewtoy) {
    Cat cat1("Sophia",23.1);
    Toy t1("linear");
    Toy t2("transformation");
    cat1.addNewToy(t1);
    cat1.addNewToy(t2);
    ASSERT_EQ(cat1.getToy(0).getName(),"linear");
    ASSERT_EQ(cat1.getToy(1).getName(),"transformation");
}
TEST(VectorTest, gettoy) {
    Cat cat1("Jose",35.2);
    Toy t1("pussy");
    Toy t2("booble");
    Toy t3("nips");
    cat1.addNewToy(t1);
    cat1.addNewToy(t2);
    cat1.addNewToy(t3);
    ASSERT_EQ(cat1.getToy(0).getName(),"pussy");
    ASSERT_EQ(cat1.getToy(1).getName(),"booble");
    ASSERT_EQ(cat1.getToy(2).getName(),"nips");
    ASSERT_THROW(cat1.getToy(3), std::string);
}

TEST(VectorTest, isheavierthan) {
    Cat cat1("Yaga",49.1);
    Cat cat2("Sophia",23.1);
    ASSERT_TRUE(cat1.isHeavierThan(cat2));
}

