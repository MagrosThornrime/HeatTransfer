#include "b_part.hpp"
#include <iomanip>
#include <iostream>


double BPart::calculateQuadrature(Function1D *func1, Function1D *func2, double integralMinX, double integralMaxX){
    double coefficient1, coefficient2, x1, x2, fx1, fx2;
    coefficient1 = (integralMaxX - integralMinX) / 2.0;
    coefficient2 = (integralMaxX + integralMinX) / 2.0;
    x1 = coefficient1 * (1.0 / std::sqrt(3.0)) + coefficient2;
    x2 = coefficient1 * (-1.0 / std::sqrt(3.0)) + coefficient2;
    fx1 = func1->getDifferentialOf(x1) * func2->getDifferentialOf(x1);
    fx2 = func1->getDifferentialOf(x2) * func2->getDifferentialOf(x2);
    return coefficient1 * (fx1 + fx2);
}


double BPart::calculateIntegralPart(BaseFunction *w, BaseFunction *v){
    double wMinX, wMaxX, vMinX, vMaxX, integralMinX, integralMaxX;
    double x1, x2, coefficient1, coefficient2;
    double fx1, fx2;

    // check for section where both functions have non-zero values
    wMinX = w->minPossibleX();
    wMaxX = w->maxPossibleX();
    vMinX = v->minPossibleX();
    vMaxX = v->maxPossibleX();
    integralMinX = std::max(wMinX, vMinX);
    integralMaxX = std::min(wMaxX, vMaxX);

    // when the section has no points, for all x in domain, in the surroundings of x,
    // one of function has constant value of 0
    // so w'v' = 0
    if (integralMinX > integralMaxX){
        return 0.0;
    }

    // calculate integral using Gaussian quadrature
    return calculateQuadrature(w, v, integralMinX, integralMaxX);
}

double BPart::calculateIntegralPart(ShiftFunction *u, BaseFunction *v){
    double integralMinX, integralMaxX;
    double x1, x2, coefficient1, coefficient2;
    double fx1, fx2;

    integralMinX = v->minPossibleX();
    integralMaxX = v->maxPossibleX();

    // calculate integral using Gaussian quadrature
    return calculateQuadrature(u, v, integralMinX, integralMaxX);

}

double BPart::calculateProductPart(BaseFunction *func1, BaseFunction *func2){
    return func1->getValueOf(0.0) * func2->getValueOf(0.0);
}

double BPart::calculateProductPart(ShiftFunction *func1, BaseFunction *func2){
    return func1->getValueOf(0.0) * func2->getValueOf(0.0);
}

double BPart::calculateValue(BaseFunction *w, BaseFunction *v){
    return calculateProductPart(w, v) - calculateIntegralPart(w, v);
}
double BPart::calculateValue(ShiftFunction *u, BaseFunction *v){
    return calculateProductPart(u, v) - calculateIntegralPart(u, v);
}