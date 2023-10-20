#include <iostream>
#include <iomanip>
#include <string>

#include "Function.h"
#include "Model.h"
#include "ModelResult.h"
#include "Newton.h"
#include "NewtonModified.h"
#include "Secant.h"

void initializeModel(Model** model, double constant, double firstStep, double thrInterval, double thrFunction, int maxIttr) {
    (*model)->setFunction(constant);
    (*model)->setFirstStep(firstStep);
    (*model)->setThrInterval(thrInterval);
    (*model)->setThrFunction(thrFunction);
    (*model)->setMaxItterations(maxIttr);
}

double setInitialGuess(Function** foo, double a, int maxIttr) {
    (*foo)->setConstant(a);

    int idx = 1;
    bool signSwapped = false;
    double previousValue = (*foo)->getValue(0);
    double nextValue;

    while (idx < maxIttr && signSwapped == false) {
        nextValue = (*foo)->getValue(0 + idx * 0.01);
        if (nextValue * previousValue < 0) {
            return 0 + idx * 0.1;
        }
        previousValue = nextValue;
        idx++;
    }
    return 0 + idx * 0.1;
}

int main() {
    std::cout << std::fixed << std::showpoint;
    

    int n;
    std::cout << "Entre o número de valores para a: ";
    std::cin >> n;

    std::cout << std::endl;

    double a[n];
    double x[n];
    Function* aux = new Function();
    for (int i = 0; i < n; i++) {
        std::cout << "Entre o valor de a" << i+1 << ": ";
        std::cin >> a[i];
        x[i] = setInitialGuess(&aux, a[i], 50);
    }

    double epsilon;
    std::cout << "Entre a precisão utilizada para computar a raíz: ";
    std::cin >> epsilon;

    std::cout << std::endl;

    Model* models[3];
    models[0] = new Newton();
    models[1] = new Secant();
    models[2] = new NewtonModified();
    std::cout << "          |   Método de Newton-Raphson    |       Método da Secante       |  Método de Newton Modificado  |" << std::endl;
    std::cout << "          |   raíz     erro1      erro2   |   raíz     erro1      erro2   |   raíz     erro1      erro2   |" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << std::setprecision(3);
        std::cout << "a = " << a[i] << " |";
        std::cout << std::setprecision(6);
        for (int j = 0; j < 3; j++) {
            initializeModel(&(models[j]), a[i], x[i], epsilon, epsilon, 100);
            models[j]->run();
            std::cout << " " << models[j]->results->root << "  " << models[j]->results->errorInterval << "  " << models[j]->results->errorFunction << "  |"; 
        } std::cout << std::endl;
    }
}