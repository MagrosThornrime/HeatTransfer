#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

// #include "b_part.hpp"
#include "l_part.hpp"

class Solver{
    std::vector<BaseFunction> baseFunctions;
    int n;
    double xMin, xMax;
    BPart *bPart;
    LPart *lPart;
    ShiftFunction *uTilde;
    std::vector<double> mainFunctionCoefficients;
    const double epsilon = 0.00001;

    void generateBaseFunctions();

    double getValue(double x);

    public:
        Solver(int n, double xMin, double xMax);

        ~Solver();

        void solve();

        std::vector<double> calculateValues(std::vector<double> &arguments);

};