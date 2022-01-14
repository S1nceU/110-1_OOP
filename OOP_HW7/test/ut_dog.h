#include <gtest/gtest.h>
#include "../src/dog.h"
#include <stdexcept>

TEST(DogTest,DogConstructor_name){
    Dog d("hello",20);
    ASSERT_EQ("hello",d.name());   
}
TEST(DogTest,DogConstructor_weight){
    Dog d("hello",20);
    ASSERT_NEAR(20.0,d.weight(),0.01);   
}
TEST(DogTest,DogConstructor_range_error){
    ASSERT_THROW(Dog d("dog01",7),std::range_error);
}
TEST(DogTest,DogFeed){
    Dog d("hello",30);
    d.feed();
    ASSERT_NEAR(30.8,d.weight(),0.01);   
}
TEST(DogTest,DogFeed_out_of_range){
    Dog d("hello",49.3);
    ASSERT_THROW(d.feed(),std::out_of_range);   
}
