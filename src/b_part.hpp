#pragma once
#include "base_function.hpp"
#include "shift_function.hpp"
#include "k_function.hpp"

class BPart{

    const double epsilon = 0.00001;
    KFunction *kFunc;

    double calculateQuadrature(Function1D *func1, Function1D *func2, double integralMinX, double integralMaxX);


    double calculateIntegralPart(Function1D *w, Function1D *v);

    double calculateProductPart(Function1D *func1, Function1D *func2);

    public:
        BPart();
        double calculateValue(Function1D *w, Function1D *v);
        ~BPart();

};