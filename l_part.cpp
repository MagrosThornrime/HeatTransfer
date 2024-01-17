#include "l_part.hpp"

double LPart::calculateLPart(BaseFunction *v){
    return 20.0 * v->getValueOf(0.0);
}


double LPart::calculateValue(BaseFunction *v){
    return calculateLPart(v) - bPart->calculateValue(uTilde, v);
}