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
    if(x < xMiddle - h - epsilon || x > xMiddle + h + epsilon){
        return 0.0;
    }

    std::cout<<std::endl << std::endl << "VALUE TEST" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "(" << xMiddle - h << ", " << xMiddle + h << ")" << std::endl;
    std::cout << "x = " << x << std::endl; 
    std::cout << "xMiddle = " << xMiddle << std::endl;
    if(x < xMiddle){
        if(xMiddle - h > xMin - epsilon){
            std::cout << "y = " << (x - xMiddle + h) / h << std::endl;
            return (x - xMiddle + h) / h;
        }
        std::cout << "y = " << 0.0 << std::endl;
        return 0.0;
    }
    if(xMiddle + h < xMax + epsilon){
        std::cout << "y = " << (xMiddle + h - x) / h << std::endl;
        return (xMiddle + h - x) / h;
    }
    std::cout << "y = " << 0.0 << std::endl;
    return 0.0;
    std::cout<<std::endl<<std::endl;
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

