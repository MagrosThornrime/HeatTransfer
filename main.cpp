#include "solver.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

std::vector<double> generateArguments(int number, double xMin, double xMax){
    std::vector<double> arguments;
    double portion = (xMax - xMin) / (double) number;
    for(int i=0; i<number; i++){
        arguments.push_back(xMin + (double)i * portion);
    }
    return arguments;
}

void writeToFile(std::vector<double> &arguments, std::vector<double> &values, std::string filename){
    std::ofstream myFile;
    myFile.open(filename);
    myFile << std::fixed << std::setprecision(5);
    for(int i=0; i<arguments.size(); i++){
        myFile << arguments[i] << " " << values[i] << std::endl;
    }
    myFile.close();
}


int main(){
    const int valuesNumber = 1000;
    const int elements = 100;
    const double xMin = 0.0;
    const double xMax = 2.0;
    const bool shouldSave = true;

    Solver solver(elements, xMin, xMax);
    std::vector<double> arguments = generateArguments(valuesNumber, xMin, xMax);
    solver.solve();
    std::vector<double> values = solver.calculateValues(arguments);
    if(shouldSave){
        writeToFile(arguments, values, "results.txt");
    }
}