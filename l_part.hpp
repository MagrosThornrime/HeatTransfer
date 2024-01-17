#pragma once

#include "b_part.hpp"

class LPart{
    BPart *bPart;
    ShiftFunction *uTilde;

    double calculateLPart(BaseFunction *v);

    public:
        LPart(BPart *bPart, ShiftFunction *uTilde) : bPart(bPart), uTilde(uTilde) {}

        double calculateValue(BaseFunction *v);
};