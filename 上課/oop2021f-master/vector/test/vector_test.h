#include "../src/math_vector.h"
#include "../src/triangle.h"
//#include "../src/add.h"

class MathVectorTest : public ::testing::Test {
protected:
    int dim;
    double v[2];
    MathVector mv;
    void SetUp() override {
        dim = 2;
        v[0] = 3;
        v[1] = 4;
        mv = MathVector(dim, v);
    }
};

TEST_F(MathVectorTest, MathVector)
{
    ASSERT_NEAR(5, mv.length(), 0.01);
}

TEST_F(MathVectorTest, MathVectorIndex)
{
    ASSERT_NEAR(3, mv.at(0), 0.01);
    ASSERT_NEAR(4, mv.at(1), 0.01);
}
constcture
TEST_F(MathVectorTest, MathVectorSet)
{
    mv.setIndex(0, 4);
    mv.setIndex(1, 3);
    ASSERT_NEAR(4, mv.at(0), 0.01);
    ASSERT_NEAR(3, mv.at(1), 0.01);
}

TEST_F(MathVectorTest, MathVectorSetException)
{
    ASSERT_THROW(mv.setIndex(2, 4), std::string);
}

TEST_F(MathVectorTest, AddMathVector)
{
    double v[2] = {3, 4};
    double v1[2] = {5, 6};
    int dim = 2;
    MathVector mv(dim, v);
    MathVector mv1(dim, v1);

    MathVector result = mv + mv1;
    ASSERT_NEAR(8.0, result.at(0), 0.001);
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_EQ(2, result.dimension());
}

/*TEST_F(Vector, AddMathVectorDiff)
{
    double v[2] = {3, 4};
    double v1[3] = {5, 6, 7};
    int dim = 2;
    int dim1 = 3;
    MathVector mv(dim, v);
    MathVector mv1(dim1, v1);

    MathVector result = add(mv, mv1);
    ASSERT_NEAR(8.0, result.at(0), 0.001);
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_NEAR(7.0, result.at(2), 0.001);
    ASSERT_EQ(2, result.dimension());
}*/

TEST_F(MathVectorTest, MathVectorAssignment)
{
    double v[2] = {3, 4};
    int dim = 2;
    MathVector mv(dim, v), mv1, mv2;
    mv1 = mv2 = mv;
    ASSERT_NEAR(3.0, mv1.at(0), 0.001);
    ASSERT_NEAR(4.0, mv1.at(1), 0.001);
    ASSERT_EQ(2, mv1.dimension());
}

TEST(Triangle, Constructor)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};
    int dim = 2;
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    Triangle t(mv, mv1, mv2);
    ASSERT_NEAR(12.0, t.perimeter(), 0.001);
}

TEST(Triangle, Array)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};

    double u1[2] = {0, -3};
    double w1[2] = {4, 0};
    double v1[2] = {0, 0};

    double u2[2] = {0, 3};
    double w2[2] = {-4, 0};
    double v2[2] = {0, 0};

    double u3[2] = {0, -3};
    double w3[2] = {-4, 0};
    double v3[2] = {0, 0};

    int dim = 2;
    
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    MathVector mv3(dim, u1), mv4(dim, w1), mv5(dim, v1);
    MathVector mv6(dim, u2), mv7(dim, w2), mv8(dim, v2);
    MathVector mv9(dim, u3), mv10(dim, w3), mv11(dim, v3);

    Triangle *t = new Triangle[4];
    t[0].perimeter(); //we will come back later to see the nullptr issue.
    ASSERT_NEAR(0.0, t[0].perimeter(), 0.001);

    if(t){
        delete [] t;
    }
    t = nullptr;
}

TEST(Triangle, Area)
{
    double u[2] = {0, 3};
    double w[2] = {4, 0};
    double v[2] = {0, 0};
    int dim = 2;
    MathVector mv(dim, u), mv1(dim, w), mv2(dim, v);
    Triangle t(mv, mv1, mv2);
    ASSERT_NEAR(6, t.area(), 0.001);
}