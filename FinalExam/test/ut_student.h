#include "../src/school_member.h"
#include "../src/student.h"

#include <stdexcept>

TEST(StudentTest,conTest){
    Student p1(123,"name","Mechanical & Electrical Engineering");
    ASSERT_EQ(p1.id(),123);
    
}


