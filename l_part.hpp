#pragma once

#include "b_part.hpp"

class LPart{
    BPart *bPart;
    ShiftFunction u;

    double calculateLPart(BaseFunction *v);

    public:
        LPart(BPart *bPart) : bPart(bPart) {}

        double calculateValue(BaseFunction *v);
};