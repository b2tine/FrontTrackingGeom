#include "Interface.h"
#include "gtest/gtest.h"


TEST(InterfaceTests, InsertCurveInterface2d)
{
    std::vector<Point> pts;
    pts.push_back(Point(0,0));
    pts.push_back(Point(1,0));
    pts.push_back(Point(1,1));
    
    Interface2d intfc2d;
    intfc2d.insertClosedCurvePoints(pts);

    /*
    ASSERT_DOUBLE_EQ(intfc2d.getPoint(0)[0], 0);
    ASSERT_DOUBLE_EQ(intfc2d.getPoint(0)[1], 0);

    ASSERT_DOUBLE_EQ(intfc2d.getPoint(1)[0], 1);
    ASSERT_DOUBLE_EQ(intfc2d.getPoint(1)[1], 0);
    
    ASSERT_DOUBLE_EQ(intfc2d.getPoint(2)[0], 1);
    ASSERT_DOUBLE_EQ(intfc2d.getPoint(2)[1], 1);
    */

    //ASSERT_EQ(intfc2d.getCurve(0).begin(),
      //      intfc2d.getCurve(0).end()->next);
}

/*
TEST(InterfaceTests, Add3dPointsToInterface)
{
    std::vector<Point> pts;
    pts.push_back(Point(0,0,0));
    pts.push_back(Point(1,0,0));
    pts.push_back(Point(1,1,1));
    
    Interface intfc;
    intfc.addPoints(pts);

    ASSERT_DOUBLE_EQ(intfc.getPoint(0)[0], 0);
    ASSERT_DOUBLE_EQ(intfc.getPoint(0)[1], 0);
    ASSERT_DOUBLE_EQ(intfc.getPoint(0)[2], 0);

    ASSERT_DOUBLE_EQ(intfc.getPoint(1)[0], 1);
    ASSERT_DOUBLE_EQ(intfc.getPoint(1)[1], 0);
    ASSERT_DOUBLE_EQ(intfc.getPoint(1)[2], 0);
    
    ASSERT_DOUBLE_EQ(intfc.getPoint(2)[0], 1);
    ASSERT_DOUBLE_EQ(intfc.getPoint(2)[1], 1);
    ASSERT_DOUBLE_EQ(intfc.getPoint(2)[2], 1);
}
*/


