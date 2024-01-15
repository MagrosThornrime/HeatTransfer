#include "b_part.hpp"

class LPart{
    BPart *bPart;
    BaseFunction *v;

    double calculateLPart();

    public:
        LPart(BPart *bPart, BaseFunction *v): bPart(bPart), v(v) {}
        double calculateValue();
};