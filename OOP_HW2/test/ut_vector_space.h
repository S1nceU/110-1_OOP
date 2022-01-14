#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_TA) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};

  double * result = add(u, 3, v, 3);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, scale_TA) {
  double u[3] = {1.5, 2.5, 3.5};

  double * result = scale(u, 3, 1.2);

  EXPECT_NEAR(1.8, result[0], DELTA);
  EXPECT_NEAR(3.0, result[1], DELTA);
  EXPECT_NEAR(4.2, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}
TEST(VectorTest, add_Test1_DifferentDim) {
  double u[4] = {1, 2, 3,77};
  double v[3] = {1.5, 2.5, 3.5};
  ASSERT_THROW(add(u, 4, v, 3),std::string);
}
TEST(VectorTest, add_Test2_negative) {
  double u[5] = {9,84,54,88,56};
  double v[4] = {5,1,3,4};
  ASSERT_THROW(add(u, -2, v, -1);,std::string);
}
TEST(VectorTest, add_Test3_zero) {
  double u[5] = {9,84,54,88,56};
  double v[4] = {5,1,3,4};
  ASSERT_THROW(add(u, 0, v, 0);,std::string);
}
TEST(VectorTest, add_Test4) {
  double u[3] = {5,6,8};
  double v[3] = {5,4,2};
  double * result = add(u, 3, v, 3);
  EXPECT_NEAR(10.0, result[0], DELTA);
  EXPECT_NEAR(10.0, result[1], DELTA);
  EXPECT_NEAR(10.0, result[2], DELTA);
  delete [] result;
}
TEST(VectorTest, scale_Test1_negative) {
  double u[3] = {1,5,8};
  ASSERT_THROW(scale(u, -1, 1.2);,std::string);
}
TEST(VectorTest, scale_Test2_zero) {
  double u[2] = {99,88};
  ASSERT_THROW(scale(u,0, 1.2);,std::string);
}
TEST(VectorTest, scale_Test3) {
  double u[3] = {3.1,5.2,6.3};

  double * result = scale(u, 3, 2.0);

  EXPECT_NEAR(6.2, result[0], DELTA);
  EXPECT_NEAR(10.4, result[1], DELTA);
  EXPECT_NEAR(12.6, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}