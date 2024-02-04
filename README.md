# HeatTransferEquation

## Introduction
Program is designed to calculate a differential equation using the finite element method. The equation and it's mathematical solution
is shown in the `report.pdf` file. It's currently only in Polish.

## Program requirements
### Main part:
- Minimum version of C++: 17
- Minimum version of CMake: 3.26
### Plotting:
- Python 3.12.1 (it may work on older versions, it just wasn't tested). All required libraries are shown in `requirements.txt` file.

## Running on Windows:
### Compilation:
Run `build.bat` file.
### Running 
In the project's main directory, open PowerShell, then run following command:
```bat
build/MES.exe <values> <elements> <should_save>
```
Where `<values>` should be an integer - its a number of points from the calculated function, to be generated. `<elements>` is a number (integer) of elements for the finite element method. `<should_save>` is a boolean flag. It should be set to `true` or `false`. If it's `true`, data will be saved to a file: `plotting/results.txt`. Then it can be accessed by the `plot.ipynb` file. Otherwise, the points will be printed in terminal.

### Example:
```bat
build/MES.exe 10 10 false
```
should print:
```
(0.00000; 398.57143)
(0.20000; 322.85714)
(0.40000; 247.14286)
(0.60000; 171.42857)
(0.80000; 95.71429)
(1.00000; 0.85714)
(1.20000; 1.28571)
(1.40000; 1.71429)
(1.60000; 2.14286)
(1.80000; 2.57143)
```

