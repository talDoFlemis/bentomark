#include "Newton.h"

Newton::Newton(){}

void Newton::setFirstStep(double step) {
    this->firstStep = step;
}

void Newton::updateNextStep() {
    this->nextStep = this->firstStep - (this->function->getValue(this->firstStep)) / (this->function->getDerivativeValue(this->firstStep));
}

void Newton::updateValues() {
    this->firstStep = this->nextStep;
}