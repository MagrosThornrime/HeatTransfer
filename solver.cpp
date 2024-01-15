#include "solver.hpp"


void Solver::generateBaseFunctions(){
    double h = 1.0/(double)n;
    for(int i=0; i<=n; i++){
        baseFunctions.emplace_back((double)i * h, h, xMin, xMax);
    }
}

Solver::Solver(int n, double xMin, double xMax) : n(n), xMin(xMin), xMax(xMax) {
    bPart = new BPart();
    lPart = new LPart(bPart);
    generateBaseFunctions();
}

Solver::~Solver(){
    delete lPart;
    delete bPart;
}

void Solver::solve(){
    std::vector<std::vector<double>> leftMatrix;
    std::vector<double> rightMatrix;
    BaseFunction *base1, *base2, *base;

    for(int i=0; i<=n; i++){
        std::vector<double> row;
        base1 = &(baseFunctions[i]);
        for(int j=0; j<=n; j++){
            base2 = &(baseFunctions[j]);
            row.push_back(bPart->calculateValue(base1, base2));
        }
        leftMatrix.push_back(row);
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    for(int i=0; i<=n; i++){
        base = &(baseFunctions[i]);
        rightMatrix.push_back(lPart->calculateValue(base));
    }

    // for(double element : rightMatrix){
    //     std::cout << std::fixed << std::setprecision(4);
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;
    // std::cout<<std::endl;

    // for(auto row : leftMatrix){
    //     for(double element : row){
    //         std::cout << std::fixed << std::setprecision(4); 
    //         std::cout << element << " ";
    //     }
    //     std::cout << std::endl;
    // }
}