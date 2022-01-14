#include <gtest/gtest.h>
#include "../src/cat.h"
#include <stdexcept>

TEST(CatTeat,CatConstructor_name){
    Cat c("hello",3);
    ASSERT_EQ("hello",c.name());   
}
TEST(CatTeat,CatConstructor_weight){
    Cat c("hello",3);
    ASSERT_NEAR(3.0,c.weight(),0.01);   
}
TEST(CatTest,CatConstructor_range_error){
    ASSERT_THROW(Cat c("cat01",7),std::range_error);
}
TEST(CatTeat,CatFeed){
    Cat c("hello",3);
    c.feed();
    ASSERT_NEAR(3.2,c.weight(),0.01);   
}
TEST(CatTeat,CatFeed_out_of_range){
    Cat c("hello",5.9);
    ASSERT_THROW(c.feed(),std::out_of_range);   
}
