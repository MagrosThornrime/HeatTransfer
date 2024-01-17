#include "shift_function.hpp"


double ShiftFunction::getValueOf(double x){
    if(x < xMax - h - epsilon || x > xMax + epsilon){
        return 0.0;
    }
    return 3.0 * (x - xMax + h) / h;
}

double ShiftFunction::getDifferentialOf(double x){
    if(x < xMax - h - epsilon || x > xMax + epsilon){
        return 0.0;
    }
    return 3.0 / h;
}
