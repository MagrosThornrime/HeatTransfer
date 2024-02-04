#include "solver.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

std::vector<double> generateArguments(int number, double xMin, double xMax){
    std::vector<double> arguments;
    double portion = (xMax - xMin) / (double) number;
    for(int i=0; i<number; i++){
        arguments.push_back(xMin + (double)i * portion);
    }
    return arguments;
}

void writeToFile(std::vector<double> &arguments, std::vector<double> &values, const std::string& filename){
    std::ofstream myFile;
    myFile.open(filename);
    if(myFile.is_open()){
        myFile << std::fixed << std::setprecision(5);
        for(int i=0; i<arguments.size(); i++){
            myFile << arguments[i] << " " << values[i] << std::endl;
        }
    }
    else{
        std::cerr << "Couldn't open file: " << filename << std::endl;
    }
    myFile.close();
}

int main(int argc, char *argv[]){
    const double X_MIN = 0.0;
    const double X_MAX = 2.0;
    int valuesNumber;
    int elements;
    bool shouldSave;

    if(!(std::istringstream(argv[1]) >> valuesNumber)){
        std::cerr << "Couldn't load number of values" << std::endl;
        return 1;
    }

    if(!(std::istringstream(argv[2]) >> elements)){
        std::cerr << "Couldn't load number of elements" << std::endl;
        return 2;
    }

    if(!(std::istringstream(argv[3]) >> std::boolalpha >> shouldSave)){
        std::cerr << "Couldn't load should_save flag" << std::endl;
        return 3;
    }


    Solver solver(elements, X_MIN, X_MAX);
    std::vector<double> arguments = generateArguments(valuesNumber, X_MIN, X_MAX);
    solver.solve();
    std::vector<double> values = solver.calculateValues(arguments);
    if(shouldSave){
        writeToFile(arguments, values, "plotting/results.txt");
    }
    else{
        std::cout << std::fixed << std::setprecision(5);
        for(int i=0; i<arguments.size(); i++){
            std::cout << "(" << arguments[i] << "; " << values[i] << ")" << std::endl;
        }
    }
}