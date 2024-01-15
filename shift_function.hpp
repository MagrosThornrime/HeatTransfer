#pragma once

#include "function1d.hpp"


class ShiftFunction : public Function1D{
    public:
        double getValueOf(double x) override;
        double getDifferentialOf(double x) override;

};