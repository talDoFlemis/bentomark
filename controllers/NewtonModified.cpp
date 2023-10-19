#include <cmath>
#include "NewtonModified.h"

NewtonModified::NewtonModified(){}

void NewtonModified::setFirstStep(double step) {
    this->firstStep = step;

    this->derivative = this->function->getDerivativeValue(step);

    while (std::abs(this->derivative) <= 0.01) {
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