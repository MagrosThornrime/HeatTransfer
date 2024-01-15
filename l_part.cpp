#include "l_part.hpp"

double LPart::calculateLPart(BaseFunction *v){
    return 20 * v->getValueOf(0);
}


double LPart::calculateValue(BaseFunction *v){
    return bPart->calculateValue(&u, v) - calculateLPart(v);
}