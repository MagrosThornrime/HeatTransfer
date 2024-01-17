#include "solver.hpp"

void printMatrices(std::vector<std::vector<double>> &leftMatrix, std::vector<double> &rightMatrix){
    for(int i=0; i<leftMatrix.size(); i++){
        for(int j=0; j<leftMatrix[i].size(); j++){
            std::cout << std::fixed << std::setprecision(4); 
            std::cout << leftMatrix[i][j] << " ";
        }
        std::cout << rightMatrix[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

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
            // std::cout << i << "-" << j << std::endl;
            row.push_back(bPart->calculateValue(base1, base2));
        }
        leftMatrix.push_back(row);
    }

    // fill right matrix with values of L'(ei)
    for(int i=0; i<n; i++){
        base = &(baseFunctions[i]);
        std::cout << i << std::endl;
        rightMatrix.push_back(lPart->calculateValue(base));
    }

    // printMatrices(leftMatrix, rightMatrix);

    // transform left matrix to an upper triangular matrix
    for(int i=0; i<n; i++){
        // divide all values of the first row by the first non-zero element
        rightMatrix[i] /= leftMatrix[i][i];
        for(int j=n-1; j>=i; j--){
            leftMatrix[i][j] /= leftMatrix[i][i];
        }

        // printMatrices(leftMatrix, rightMatrix);

        // subtract all next rows by a multiplication of the first row
        // till all their first non-zero elements are zeros
        for(int j=i+1; j<n; j++){
            rightMatrix[j] -= leftMatrix[j][i] * rightMatrix[i];
            for(int k=n-1; k>=i; k--){
                leftMatrix[j][k] -= leftMatrix[j][i] * leftMatrix[i][k];
            }
        }

        // printMatrices(leftMatrix, rightMatrix);
    }

    // transform the left matrix to a diagonal matrix
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            rightMatrix[j] -= leftMatrix[j][i] * rightMatrix[i];
            leftMatrix[j][i] = 0.0;
        }
        // printMatrices(leftMatrix, rightMatrix);
    }

    mainFunctionCoefficients = rightMatrix;
}

double Solver::getValue(double x){
    double baseMin, baseMax, result, coefficient;

    // std::cout << std::fixed << std::setprecision(4);
    // std::cout << x << std::endl;

    if(x < xMin - epsilon|| x > xMax + epsilon){
        return 0.0;
    }

    result = uTilde->getValueOf(x);
    // std::cout << result << std::endl;
    for(int i=0; i<n; i++){

        coefficient = mainFunctionCoefficients[i];
        result += coefficient * baseFunctions[i].getValueOf(x);
        // std::cout << result << std::endl;
    }
    // std::cout << std::endl << std::endl;
    return result;

}

std::vector<double> Solver::calculateValues(std::vector<double> &arguments){
    std::vector<double> results;
    for(auto x: arguments){
        results.push_back(getValue(x));
    }
    return results;
}