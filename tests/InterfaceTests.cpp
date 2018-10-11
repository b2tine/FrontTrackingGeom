#include "Interface.h"
#include "gtest/gtest.h"


TEST(CurveTests, Create2dCurve)
{
    Point a(0,0);
    Point b(1,0);
    Point c(1,1);
    Point d(0,1);

    std::vector<Point> pts;
    pts.push_back(a);
    pts.push_back(b);
    pts.push_back(c);
    pts.push_back(d);
    
    Curve curve(pts);
    auto cit = curve.cbegin();

    auto p = *cit;
    ASSERT_DOUBLE_EQ(p[0], 0);
    ASSERT_DOUBLE_EQ(p[1], 0);
    cit++;

    p = *cit;
    ASSERT_DOUBLE_EQ(p[0], 1);
    ASSERT_DOUBLE_EQ(p[1], 0);
    cit++;

    p = *cit;
    ASSERT_DOUBLE_EQ(p[0], 1);
    ASSERT_DOUBLE_EQ(p[1], 1);
    cit++;

    p = *cit;
    ASSERT_DOUBLE_EQ(p[0], 0);
    ASSERT_DOUBLE_EQ(p[1], 1);
}

