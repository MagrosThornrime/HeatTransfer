#include "function1d.hpp"


class BaseFunction : Function1D{
    double xMiddle, h, xMin, xMax;

    public:
        BaseFunction(double xMiddle, double h, double xMin, double xMax): xMiddle(xMiddle), h(h), xMin(xMin), xMax(xMax) {}

};
