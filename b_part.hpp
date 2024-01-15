#include "base_function.hpp"

class BPart{
    BaseFunction *w, *v;

    double calculateIntegralPart();
    double calculateProductPart();

    public:
        BPart(BaseFunction *w, BaseFunction *v) : w(w), v(v) {}
        double calculateValue();

};