#include "function1d.hpp"


class ShiftFunction : Function1D{
    public:
        double getValueOf(double x){
            return 3 * x / 2;
        }
        double getDifferentialOf(double x){
            return 3 / 2;
        }

};