#include "b_part.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>


double BPart::calculateQuadrature(Function1D *func1, Function1D *func2, double integralMinX, double integralMaxX){
    // std::cout<<"integral" << std::endl;
    // std::cout << std::fixed << std::setprecision(4);
    // std::cout<<"("<<integralMinX << ", " << integralMaxX << ")"<<std::endl;

    double coefficient1, coefficient2, x1, x2, fx1, fx2;
    coefficient1 = (integralMaxX - integralMinX) / 2.0;
    coefficient2 = (integralMaxX + integralMinX) / 2.0;
    x1 = coefficient1 * (1.0 / std::sqrt(3.0)) + coefficient2;
    x2 = coefficient1 * (-1.0 / std::sqrt(3.0)) + coefficient2;
    fx1 = func1->getDifferentialOf(x1) * func2->getDifferentialOf(x1);
    fx2 = func1->getDifferentialOf(x2) * func2->getDifferentialOf(x2);
    double result = coefficient1 * (fx1 + fx2);
    // std::cout << result << std::endl;
    return result;
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

    // std::cout<<"w " << wMinX << " " <<wMaxX << std::endl;
    // std::cout<< "v " << vMinX << " " << vMaxX << std::endl;

    // when the section has no points, for all x in domain, in the surroundings of x,
    // one of functions has constant value of 0
    // so w'v' = 0
    if (integralMinX > integralMaxX){
        // std::cout<<std::endl << std::endl;
        return 0.0;
    }
    // std::cout<<"nonzero" << std::endl <<std::endl;;

    // calculate integral using Gaussian quadrature
    return calculateQuadrature(w, v, integralMinX, integralMaxX);
}

double BPart::calculateIntegralPart(ShiftFunction *u, BaseFunction *v){
    double vMinX, vMaxX, uMinX, uMaxX, integralMinX, integralMaxX;
    double x1, x2, coefficient1, coefficient2;
    double fx1, fx2;

    uMinX = u->getXMin();
    uMaxX = u->getXMax();
    vMinX = v->minPossibleX();
    vMaxX = v->maxPossibleX();
    integralMinX = std::max(uMinX, vMinX);
    integralMaxX = std::min(uMaxX, vMaxX);

    // std::cout<<"u " << uMinX << " " << uMaxX << std::endl;
    // std::cout << "v" << vMinX << " " << vMaxX << std::endl;
    // std::cout << "int " << integralMinX << " " << integralMaxX << std::endl;


    if (integralMinX > integralMaxX){
        // std::cout<<"flag" << std::endl;
        // std::cout<<std::endl << std::endl;
        return 0.0;
    }


    // calculate integral using Gaussian quadrature
    return calculateQuadrature(u, v, integralMinX, integralMaxX);

}

double BPart::calculateProductPart(BaseFunction *func1, BaseFunction *func2){
    double val1, val2;
    val1 = func1->getValueOf(0.0);
    val2 = func2->getValueOf(0.0);
    // std::cout <<"product" << std::endl;
    // std::cout << std::fixed << std::setprecision(4);
    // std::cout<<val1 << " " << val2 << std::endl;
    return val1  *  val2;
}

double BPart::calculateProductPart(ShiftFunction *func1, BaseFunction *func2){
    double val1, val2;
    val1 = func1->getValueOf(0.0);
    val2 = func2->getValueOf(0.0);
    // std::cout <<"product" << std::endl;
    // std::cout << std::fixed << std::setprecision(4);
    // std::cout<<val1 << " " << val2 << std::endl;
    return val1  *  val2;
}

double BPart::calculateValue(BaseFunction *w, BaseFunction *v){
    // std::cout<<"test"<<std::endl;
    double val = calculateProductPart(w, v) - calculateIntegralPart(w, v);
    // std::cout<<std::endl;
    // std::cout<<std::endl;
    return val;
}
double BPart::calculateValue(ShiftFunction *u, BaseFunction *v){
    // std::cout<<"test"<<std::endl;
    double val1 = calculateProductPart(u, v);
    double val2 = calculateIntegralPart(u, v);
    // std::cout<<"product: " << val1 << std::endl;
    // std::cout<<"integral: " << val2 << std::endl;
    // std::cout<<std::endl;
    return val1 - val2;
}