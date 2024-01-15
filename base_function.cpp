#include "base_function.hpp"
#include <iomanip>
#include <iostream>

double BaseFunction::minPossibleX(){
    return std::max(xMiddle - h, xMin);
}

double BaseFunction::maxPossibleX(){
    return std::min(xMiddle + h, xMax);
}

double BaseFunction::getValueOf(double x) {
    if(x < xMiddle){
        if(xMiddle - h > xMin - epsilon){
            return (x - xMiddle + h) / h;
        }
        return 0.0;
    }
    if(xMiddle + h < xMax + epsilon){
        return (xMiddle + h - x) / h;
    }
    return 0.0;
}

double BaseFunction::getDifferentialOf(double x){
    // std::cout << "differential of" << std::endl;
    // std::cout << std::fixed << std::setprecision(4);
    // std::cout << x << " " << xMiddle << std::endl;
    // std::cout << "endofdiff" << std::endl;
    if(x < xMiddle){
        if(xMiddle - h > xMin - epsilon){
            return 1.0/h;
        }
        return 0.0;
    }
    if(xMiddle + h < xMax + epsilon){
        return -1.0/h;
    }
    return 0.0;
}

