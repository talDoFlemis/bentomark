#include "NewtonModified.h"

NewtonModified::NewtonModified(){}

double absoluteValue(double x) {
    if (x >= 0) return x;
    return -x;
}

void NewtonModified::setFirstStep(double step) {
    this->firstStep = step;

    this->derivative = this->function->getDerivativeValue(step);

    while (absoluteValue(this->derivative) <= 0.01) {
        if (this->derivative < 0) this->derivative -= 0.01;
        if (this->derivative >= 0) this->derivative += 0.01;
    }
}

void NewtonModified::updateNextStep() {
    this->nextStep = this->firstStep - (this->function->getValue(this->firstStep)) / (this->derivative);
}

void NewtonModified::updateValues() {
    this->firstStep = this->nextStep;
}