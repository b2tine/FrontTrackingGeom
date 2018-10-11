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

class Bond
{
    private:

        Point p1;
        Point p2;

    public:
    
        Bond() = default;
        Bond(const Bond&) = default;
        Bond& operator=(const Bond&) = default;
        Bond(Bond&&) = default;
        Bond& operator=(Bond&&) = default;
        ~Bond() = default;

        Bond(const Point& p, const Point& q)
            : p1{p}, p2{q}
        {}

        const Point& operator[](const std::size_t i) const
        {
            assert(i == 0 || i == 1);
            return i == 0 ? p1 : p2;
        }

        Point& operator[](const std::size_t i)
        {
            const_cast<Point&>(
                    static_cast<const Bond&>(*this)[i]);
        }
};


class Curve
{
    private:

        std::list<Bond> segments;

    public:

        Curve() = default;
        Curve(const Curve&) = default;
        Curve& operator=(const Curve&) = default;
        Curve(Curve&&) = default;
        Curve& operator=(Curve&&) = default;
        ~Curve() = default;

};


class Interface
{
    protected:

        std::vector<std::vector<Point> > points;
        std::vector<Curve> curves;

    public:

        Interface() = default;
        ~Interface() = default;

        Interface(const Interface&) = delete;
        Interface& operator=(const Interface&) = delete;
        Interface(Interface&&) = delete;
        Interface& operator=(Interface&&) = delete;

        virtual const int getDim() const = 0;

        /*
        const Point& getPoint(const std::size_t i) const
        {
            assert(i < points.size());
            return points[i];
        }

        const Curve& getCurve(const std::size_t i) const
        {
            assert(i < curves.size());
            return curves[i];
        }
        */
};

class Interface2d : public Interface
{
    private:

        void insertClosedCurve(const std::vector<Point>& pts)
        {

        }

    public:

        Interface2d() = default;
        ~Interface2d() = default;

        Interface2d(const Interface2d&) = delete;
        Interface2d& operator=(const Interface2d&) = delete;
        Interface2d(Interface2d&&) = delete;
        Interface2d& operator=(Interface2d&&) = delete;

        const int getDim() const override {return 2;}

        void insertClosedCurvePoints(const std::vector<Point>& pts)
        {
            //points.assign(pts.begin(),pts.end());
            insertClosedCurved(pts);
        }

};


class Interface3d : public Interface
{
    public:

        Interface3d() = default;
        ~Interface3d() = default;

        Interface3d(const Interface3d&) = delete;
        Interface3d& operator=(const Interface3d&) = delete;
        Interface3d(Interface3d&&) = delete;
        Interface3d& operator=(Interface3d&&) = delete;

        const int getDim() const override {return 3;}


};





