#include <gtest/gtest.h>
#include "\LABA2.2\StaticLib2\StaticLib2\relclass.h"
TEST(LineConstructor, TestException)
{
    Prog2::Line L(1, 1);
    ASSERT_ANY_THROW(Prog2::Line(0, 5));
    ASSERT_ANY_THROW(Prog2::Line(-6, 5));
    ASSERT_ANY_THROW(Prog2::Line(7, -10));
    ASSERT_ANY_THROW(Prog2::Line(7, 0));
    ASSERT_ANY_THROW(L.set_R(0));
    ASSERT_ANY_THROW(L.set_R(-1));
    ASSERT_ANY_THROW(L.set_a(0));
    ASSERT_ANY_THROW(L.set_a(-1));

}

TEST(LineConstuctor, Setters)
{
    Prog2::Line L(1, 2);
    ASSERT_EQ(1.00, L.get_a());
    ASSERT_EQ(2.00, L.get_R());
    L.set_a(3);
    ASSERT_EQ(3.00, L.get_a());
    L.set_R(4);
    ASSERT_EQ(4.00, L.get_R());
}

TEST(LineMethods, Methods)
{
    double err = 0.001;
    Prog2::Line L(3, 10);
    ASSERT_NEAR(2.09416, L.find_lenght(2, 4, L.get_R()),err);
    ASSERT_NEAR(2.09416, L.find_lenght(4, 2, L.get_R()), err);
    ASSERT_NEAR(0, L.find_lenght(4, 4, L.get_R()), err);

    ASSERT_NEAR(7.14329, L.find_Radius(3, L.get_a()),err);
    ASSERT_NEAR(7.14329, L.find_Radius(-3, L.get_a()), err);
    ASSERT_NEAR(3, L.find_Radius(0, L.get_a()), err);

    double* p = 0;
    p = L.find_centre(5, L.get_a());
    ASSERT_NEAR(15.997, *p, err);
    p++;
    ASSERT_NEAR(16.4501, *p, err);
    p--;
    delete[] p;
    p = L.find_centre(-5, L.get_a());
    ASSERT_NEAR(-15.997, *p, err);
    p++;
    ASSERT_NEAR(16.4501, *p, err);
    p--;
    delete[] p;
    p = L.find_centre(0, L.get_a());
    ASSERT_NEAR(0, *p, err);
    p++;
    ASSERT_NEAR(6, *p, err);
    p--;
    delete[] p;


    ASSERT_NEAR(3.39856, L.find_square(1,2, L.get_a()), err);
    ASSERT_NEAR(3.39856, L.find_square(2,1, L.get_a()), err);
    ASSERT_NEAR(0, L.find_square(1,1, L.get_a()), err);

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}