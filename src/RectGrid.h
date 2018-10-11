#include <iostream>
#include <cassert>
#include <vector>
#include <list>


class RectGrid
{
    private:

        int dim;
        double L[3];
        double U[3];
        double h[3];
        int nblocks[3];

    public:

        RectGrid() = default;
        RectGrid(const RectGrid&) = default;
        RectGrid& operator=(const RectGrid&) = default;
        ~RectGrid() = default;

        RectGrid(RectGrid&&) = delete;
        RectGrid& operator=(RectGrid&&) = delete;
};
