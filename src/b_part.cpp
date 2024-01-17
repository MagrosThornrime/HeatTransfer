#include "b_part.hpp"
#include <cmath>


double BPart::calculateQuadrature(Function1D *func1, Function1D *func2, double integralMinX, double integralMaxX){
    double coefficient1, coefficient2, x1, x2, fx1, fx2;
    coefficient1 = (integralMaxX - integralMinX) / 2.0;
    coefficient2 = (integralMaxX + integralMinX) / 2.0;
    x1 = coefficient1 * (1.0 / std::sqrt(3.0)) + coefficient2;
    x2 = coefficient1 * (-1.0 / std::sqrt(3.0)) + coefficient2;
    fx1 = func1->getDifferentialOf(x1) * func2->getDifferentialOf(x1) * kFunc->getValueOf(x1);
    fx2 = func1->getDifferentialOf(x2) * func2->getDifferentialOf(x2) * kFunc->getValueOf(x2);
    return coefficient1 * (fx1 + fx2);
}


double BPart::calculateIntegralPart(Function1D *w, Function1D *v){
    double wMinX, wMaxX, vMinX, vMaxX, integralMinX, integralMaxX;

    // check for section where both functions have non-zero values
    wMinX = w->minPossibleX();
    wMaxX = w->maxPossibleX();
    vMinX = v->minPossibleX();
    vMaxX = v->maxPossibleX();
    integralMinX = std::max(wMinX, vMinX);
    integralMaxX = std::min(wMaxX, vMaxX);

    // when the section has no points, for all x in domain, in the surroundings of x,
    // one of functions has constant value of 0
    // so w'v' = 0
    if (integralMinX > integralMaxX){
        return 0.0;
    }
    // calculate integral using Gaussian quadrature
    return calculateQuadrature(w, v, integralMinX, integralMaxX);
}

double BPart::calculateProductPart(Function1D *func1, Function1D *func2){
    return func1->getValueOf(0.0) * func2->getValueOf(0.0);
}

double BPart::calculateValue(Function1D *w, Function1D *v){
    return calculateProductPart(w, v) - calculateIntegralPart(w, v);
}

BPart::BPart(){
    kFunc = new KFunction(0.0, 2.0);
}

BPart::~BPart(){
    delete kFunc;
}