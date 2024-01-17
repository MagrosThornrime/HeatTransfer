#pragma once

class Function1D{
    public:
        virtual double getValueOf(double x) {return 0.0;}
        virtual double getDifferentialOf(double x) {return 0.0;}
        virtual double minPossibleX() {return 0.0;}
        virtual double maxPossibleX() {return 0.0;}
};