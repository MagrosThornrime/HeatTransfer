#pragma once
#include "base_function.hpp"
#include "shift_function.hpp"
#include <cmath>

class BPart{

    double calculateQuadrature(Function1D *func1, Function1D *func2, double integralMinX, double integralMaxX);


    double calculateIntegralPart(BaseFunction *w, BaseFunction *v);

    double calculateIntegralPart(ShiftFunction *u, BaseFunction *v);

    double calculateProductPart(BaseFunction *func1, BaseFunction *func2);

    double calculateProductPart(ShiftFunction *func1, BaseFunction *func2);

    public:
        BPart() {}
        double calculateValue(BaseFunction *w, BaseFunction *v);
        double calculateValue(ShiftFunction *u, BaseFunction *v);

};