#include "shift_function.hpp"


double ShiftFunction::getValueOf(double x){
    return 3.0 * x / 2.0;
}
double ShiftFunction::getDifferentialOf(double x){
    return 3.0 / 2.0;
}
