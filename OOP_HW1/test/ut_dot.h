#include "../src/dot.h"

TEST(InnerProductTest,InnerProduct_2){
	double u[2] = {10,10};
	int dim_u = 2;
	double v[2] = {2,2};
	int dim_v = 2;
	ASSERT_NEAR(40,dot(u,dim_u,v,dim_v),0.01);
}
TEST(InnerProductTest,InnerProduct_2_2){
	double u[2] = {5,5};
	int dim_u = 2;
	double v[2] = {7,7};
	int dim_v = 2;
	ASSERT_NEAR(70,dot(u,dim_u,v,dim_v),0.01);
}
TEST(InnerProductTest,InnerProduct_3){
	double u[3] = {6,7,-8};
	int dim_u = 3;
	double v[3] = {1,2,1};
	int dim_v = 3;
	ASSERT_NEAR(12,dot(u,dim_u,v,dim_v),0.01);
}
TEST(InnerProductTest,InnerProduct_3_3){
	double u[3] = {-10,-6,-1};
	int dim_u = 3;
	double v[3] = {2,-9,10};
	int dim_v = 3;
	ASSERT_NEAR(24,dot(u,dim_u,v,dim_v),0.01);
}
TEST(InnerProductTest,InnerProduct_exception){
	double u[3] = {999,888,777};
	int dim_u = 3;
	double v[4] = {1,2,3,4};
	int dim_v = 4;
	ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
}
TEST(InnerProductTest,InnerProduct_exception_2){
	double u[3] = {24,55,76};
	int dim_u = 3;
	double v[4] = {55,77,82,987};
	int dim_v = 4;
	ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
}
TEST(InnerProductTest,InnerProduct_exception_n1){
	double u[3] = {999,888,777};
	int dim_u = -1;
	double v[4] = {1,9,5,1};
	int dim_v = -1;
	ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
}
TEST(InnerProductTest,InnerProduct_exception_n1_2){
	double u[3] = {75,86,94};
	int dim_u = -1;
	double v[4] = {8,14,21,56};
	int dim_v = -1;
	ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
}
