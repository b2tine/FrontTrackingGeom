#include <iostream>
#include <cassert>
#include <vector>
#include <list>


class Point
{
    private:
     
        int dim {3}; 
        double elem[3];

    public:
    
        Point() = default;
        Point(const Point&) = default;
        Point& operator=(const Point&) = default;
        Point(Point&&) = default;
        Point& operator=(Point&&) = default;
        ~Point() = default;

        Point(double x, double y)
            : dim{2}
        {
            elem[0] = x;
            elem[1] = y;
            elem[2] = 0;
        }

        Point(double x, double y, double z)
        {
            elem[0] = x;
            elem[1] = y;
            elem[2] = z;
        }

        const double& operator[](const std::size_t i) const
        {
            assert(i >= 0 && i < dim);
            return elem[i];
        }

        double& operator[](const std::size_t i)
        {
            const_cast<double&>(
                    static_cast<const Point&>(*this)[i]);
        }
};


class Curve
{
    private:

        std::list<Point> points;

    public:

        Curve() = default;
        Curve(const Curve&) = default;
        Curve& operator=(const Curve&) = default;
        ~Curve() = default;

        Curve(Curve&&) = delete;
        Curve& operator=(Curve&&) = delete;

        Curve(const std::vector<Point>& pts)
        {
            points.assign(pts.begin(),pts.end());
        }

        std::list<Point>::const_iterator cbegin() const
        {
            return points.cbegin();
        }

};

