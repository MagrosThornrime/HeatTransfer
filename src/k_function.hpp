#pragma once
#include <algorithm>
#include "function1d.hpp"


class KFunction : public Function1D{
    double xMin, xMax, xMiddle;
    const double epsilon = 0.00001;

    public:

        KFunction(double xMin, double xMax);

        double minPossibleX() override;

        double maxPossibleX() override;

        double getValueOf(double x) override;

        double getDifferentialOf(double x) override;
};
