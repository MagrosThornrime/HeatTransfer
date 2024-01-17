#include "k_function.hpp"

KFunction::KFunction(double xMin, double xMax): xMin(xMin), xMax(xMax) {
    xMiddle = (xMax - xMin)/2.0;
    xMiddle = 1.0;
}

double KFunction::minPossibleX(){
    return xMin;
}

double KFunction::maxPossibleX(){
    return xMax;
}

double KFunction::getValueOf(double x){
    if(x < xMin - epsilon || x > xMax + epsilon){
        return 0.0;
    }
    if(x < xMiddle + epsilon){
        return 1.0;
    }
    return 2.0;
};

double KFunction::getDifferentialOf(double x){
    return 0.0;
};
