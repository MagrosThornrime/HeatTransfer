#include "base_function.hpp"

double BaseFunction::minPossibleX(){
    return std::max(xMiddle - h, xMin);
}

double BaseFunction::maxPossibleX(){
    return std::min(xMiddle + h, xMax);
}

double BaseFunction::getValueOf(double x) {
    if(x < xMiddle - h - epsilon || x > xMiddle + h + epsilon){
        return 0.0;
    }

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

