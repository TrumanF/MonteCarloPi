#include <iostream>
#include "Simulation.h"
#include "GenerateCN.h"
#include <cmath>
#include "MathFunction.h"
#include <Python.h>


int main() {

    std::cout << Simulation().run(100000000, 2) << std::endl;

    char filename[] = "TestPy.py";
    Py_Initialize();

    FILE *PythonScriptFile;

    PythonScriptFile = _Py_fopen(filename, "r");
    PyRun_SimpleFile(PythonScriptFile, filename);


    Py_Finalize();
    return 0;
}
