#pragma once

#include "function1d.hpp"


class ShiftFunction : public Function1D{

    double h, xMax;
    const double epsilon = 0.00001;

    public:
        ShiftFunction(double h, double xMax) : h(h), xMax(xMax) {}
        double getValueOf(double x) override;
        double getDifferentialOf(double x) override;
        double getXMin() {return xMax - h;}
        double getXMax() {return xMax;}

};