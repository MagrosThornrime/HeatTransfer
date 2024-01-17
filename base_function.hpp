#pragma once
#include <algorithm>
#include "function1d.hpp"


class BaseFunction : public Function1D{
    double xMiddle, h, xMin, xMax;
    const double epsilon = 0.00001;

    public:

        BaseFunction(double xMiddle, double h, double xMin, double xMax): xMiddle(xMiddle), h(h), xMin(xMin), xMax(xMax) {}

        double minPossibleX() override;

        double maxPossibleX() override;

        double getValueOf(double x) override;

        double getDifferentialOf(double x) override;
};
