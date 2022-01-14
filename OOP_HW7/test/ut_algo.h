#include "../src/pet.h"
#include <gtest/gtest.h>
#include "../src/dog.h"
#include "../src/algo.h"
#include "../src/cat.h"
TEST(algoTest,LargerWeight){
    Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
    ASSERT_NEAR(maxPet(arr.begin(), arr.end(),pet_comp::largerWeight)[0]->weight(), 30,0.01);
}
TEST(algoTest,LongerName){
    Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
    ASSERT_EQ(maxPet(arr.begin(), arr.end(),pet_comp::longerName)[0]->name(),"sosososo");
}