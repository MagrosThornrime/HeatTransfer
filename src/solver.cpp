#include "solver.hpp"

void Solver::generateBaseFunctions(){
    double h = 2.0/(double)n;
    for(int i=0; i<n; i++){
        baseFunctions.emplace_back((double)i * h, h, xMin, xMax);
    }
}

Solver::Solver(int n, double xMin, double xMax) : n(n), xMin(xMin), xMax(xMax) {
    bPart = new BPart();
    uTilde = new ShiftFunction(2.0/n, xMax);
    lPart = new LPart(bPart, uTilde);
    generateBaseFunctions();
}

Solver::~Solver(){
    delete lPart;
    delete uTilde;
    delete bPart;
}

void Solver::solve(){
    std::vector<std::vector<double>> leftMatrix;
    std::vector<double> rightMatrix;
    BaseFunction *base1, *base2, *base;

    // fill left matrix with values of B(ei, ej)
    for(int i=0; i<n; i++){
        std::vector<double> row;
        base1 = &(baseFunctions[i]);
        for(int j=0; j<n; j++){
            base2 = &(baseFunctions[j]);
            row.push_back(bPart->calculateValue(base1, base2));
        }
        leftMatrix.push_back(row);
    }

    // fill right matrix with values of L'(ei)
    for(int i=0; i<n; i++){
        base = &(baseFunctions[i]);
        rightMatrix.push_back(lPart->calculateValue(base));
    }

    // transform left matrix to an upper triangular matrix
    for(int i=0; i<n; i++){
        // divide all values of the first row by the first non-zero element
        if(std::abs(leftMatrix[i][i]) < epsilon){
            continue;
        }
        rightMatrix[i] /= leftMatrix[i][i];
        for(int j=n-1; j>=i; j--){
            leftMatrix[i][j] /= leftMatrix[i][i];
        }


        // subtract all next rows by a multiplication of the first row
        // till all their first non-zero elements are zeros
        for(int j=i+1; j<n; j++){
            rightMatrix[j] -= leftMatrix[j][i] * rightMatrix[i];
            for(int k=n-1; k>=i; k--){
                leftMatrix[j][k] -= leftMatrix[j][i] * leftMatrix[i][k];
            }
        }

    }

    // transform the left matrix to a diagonal matrix
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            rightMatrix[j] -= leftMatrix[j][i] * rightMatrix[i];
            leftMatrix[j][i] = 0.0;
        }

    }

    mainFunctionCoefficients = rightMatrix;
}

double Solver::getValue(double x){
    double result, coefficient;

    if(x < xMin - epsilon|| x > xMax + epsilon){
        return 0.0;
    }

    result = uTilde->getValueOf(x);
    for(int i=0; i<n; i++){

        coefficient = mainFunctionCoefficients[i];
        result += coefficient * baseFunctions[i].getValueOf(x);
    }
    return result;

}

std::vector<double> Solver::calculateValues(std::vector<double> &arguments){
    std::vector<double> results;
    for(auto x: arguments){
        results.push_back(getValue(x));
    }
    return results;
}