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

    void generateBaseFunctions();

    public:
        Solver(int n, double xMin, double xMax);

        ~Solver();

        void solve();

};