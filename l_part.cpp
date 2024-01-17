#include "l_part.hpp"
#include <iomanip>
#include <iostream>

double LPart::calculateLPart(BaseFunction *v){
    return 20.0 * v->getValueOf(0.0);
}


double LPart::calculateValue(BaseFunction *v){
    double val1 = calculateLPart(v);
    double val2 = bPart->calculateValue(uTilde, v);
    std::cout << std::fixed << std::setprecision(4);
    std::cout<< "lpart " << val1 << std::endl;
    std::cout<<"Bpart " << val2 << std::endl;
    return val1 - val2;
}